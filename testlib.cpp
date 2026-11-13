#include <iostream>
#include "Logger.h"
#include "Config.h"

using namespace std;

int main() {
    Logger::getInstance().log("Demarrage du programme");

    Config config;

    string application =
        config.lireValeur("config.json", "application");

    string version =
        config.lireValeur("config.json", "version");

    cout << "Application : " << application << endl;
    cout << "Version : " << version << endl;

    Logger::getInstance().log("Fin du programme");

    return 0;
}