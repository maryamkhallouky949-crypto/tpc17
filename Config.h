#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    std::string lireValeur(
        const std::string& nomFichier,
        const std::string& cle
    );
};

#endif