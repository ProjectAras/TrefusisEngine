//
// Created by elsa on 15.04.2020.
//

#ifndef TREFUSISENGINE_TREFUSISCONFIG_H
#define TREFUSISENGINE_TREFUSISCONFIG_H


#include <string>
#include <vector>

class TrefusisConfig {
public:
    static std::string configFile;
    static std::string mapsDirectory;
    static std::string tilemapLocation;
    static std::string prefix;
    static const int deltaTime = 1000;
    static const int tileSize = 32;
    static const int screenWidth = 640;
    static const int screenHeight = 480;
    static std::vector<std::string> mapFileNames;
    static bool isInitialised;
    /**
     * Initialise the config object.
     * @param fileName Filename to the main trefusis.conf
     * @return If config object is initialised, false if config file not found.
     */
    static bool initConfig(std::string fileName);
};


#endif //TREFUSISENGINE_TREFUSISCONFIG_H
