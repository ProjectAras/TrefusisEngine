//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_GAMEMANAGER_H
#define TREFUSISENGINE_GAMEMANAGER_H

#include <vector>
#include <string>
#include "../objects/Character.h"

class GameManager {
private:
    std::vector<Character> characters;
    void trackObjects();
public:
    void Update();
    GameManager();
    GameManager(std::string saveFile);
};


#endif //TREFUSISENGINE_GAMEMANAGER_H
