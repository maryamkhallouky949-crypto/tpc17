#include "Config.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string Config::lireValeur(
    const string& nomFichier,
    const string& cle
) {
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier."
             << endl;
        return "";
    }

    string ligne;

    while (getline(fichier, ligne)) {
        size_t position = ligne.find("\"" + cle + "\"");

        if (position != string::npos) {
            size_t deuxPoints = ligne.find(":", position);

            if (deuxPoints == string::npos) {
                return "";
            }

            size_t debut = ligne.find_first_not_of(
                " \t\"", deuxPoints + 1
            );

            if (debut == string::npos) {
                return "";
            }

            size_t fin;

            if (ligne[debut] == '"') {
                debut++;
                fin = ligne.find('"', debut);
            } else {
                fin = ligne.find_first_of(",}", debut);
            }

            if (fin == string::npos) {
                fin = ligne.find_last_not_of(" \t\r");
                return ligne.substr(debut, fin - debut + 1);
            }

            return ligne.substr(debut, fin - debut);
        }
    }

    return "";
}