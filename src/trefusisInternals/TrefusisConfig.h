//
// Created by elsa on 15.04.2020.
//

#ifndef TREFUSISENGINE_TREFUSISCONFIG_H
#define TREFUSISENGINE_TREFUSISCONFIG_H


#include <string>

class TrefusisConfig {
public:
    static std::string configFile;
    static std::string mapsDirectory;
    static std::string tilemapLocation;
    static bool isInitialised;
    /**
     * Initialise the config object.
     * @param fileName Filename to the main trefusis.conf
     * @return If config object is initialised, false if config file not found.
     */
    static bool initConfig(std::string fileName);
};


#endif //TREFUSISENGINE_TREFUSISCONFIG_H
