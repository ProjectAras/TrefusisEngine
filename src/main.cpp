//
// Created by elsa on 12.04.2020.
//

#include <stdio.h>
#include <iostream>
#include "managers/GameManager.h"
#include "trefusisInternals/TrefusisConfig.h"
#include "harlequin/DialogManager.hpp"

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
#endif
    GameManager gm = GameManager::getInstance();
    DialogManager::addDialog(Dialog{"player", "It is so cold."});
    while (!gm.quit) {
        SDL_Delay(TrefusisConfig::deltaTime);
        gm.Update();
    }
    gm.close();
}
