//
// Created by elsa on 12.04.2020.
//

#include <stdio.h>
#include <iostream>
#include "managers/GameManager.h"
#include "trefusisInternals/TrefusisConfig.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[]){
#ifdef DEBUG
    bool fileFound = TrefusisConfig::initConfig("../trefusis.conf");
#elif PROD
    bool fileFound = TrefusisConfig::initConfig("trefusis.conf");
#endif

#ifdef DEBUG
    std::cout << TrefusisConfig::configFile << "Maps directory: " << TrefusisConfig::mapsDirectory << " List of maps: \n";
    for (auto mapName : TrefusisConfig::mapFileNames) {
        std::cout << mapName << "\n";
    }
    if (!fileFound) {
        std::cout << "Config file not found\n";
    }
#endif
    GameManager gm = GameManager::getInstance();
    while (!gm.quit) {
        SDL_Delay(TrefusisConfig::deltaTime);
        gm.Update();
    }
    gm.close();
}
