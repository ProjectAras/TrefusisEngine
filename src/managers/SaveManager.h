//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_SAVEMANAGER_H
#define TREFUSISENGINE_SAVEMANAGER_H


#include "GameManager.h"

class SaveManager {
public:
    GameManager loadGame(std::string fileName);
    void saveGame(std::string fileName, GameManager gameManager);
};


#endif //TREFUSISENGINE_SAVEMANAGER_H
