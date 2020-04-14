//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_GAMEMANAGER_H
#define TREFUSISENGINE_GAMEMANAGER_H

#include <vector>
#include <string>
#include "../objects/Character.h"
#include "TimeManager.h"
#include "GraphicsManager.h"

class GameManager {
private:
    std::vector<Character> characters;
    TimeManager timeManager;
    GraphicsManager graphicsManager;
    SDL_Event e;
    void trackObjects();
    void showSplashScreen();
    void handleKeys();
public:
    bool quit;
    void Update();
    GameManager();
    void close();
    GameManager(std::string saveFile);
};


#endif //TREFUSISENGINE_GAMEMANAGER_H
