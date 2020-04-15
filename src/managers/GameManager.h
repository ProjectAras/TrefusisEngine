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

/**
 * A singleton class, GameManager has only one active instance at any given time.
 */
class GameManager {
private:
    std::vector<Character> characters;
    TimeManager timeManager;
    GraphicsManager graphicsManager;
    SDL_Event e;
    static GameManager* game;
    void trackObjects();
    void showSplashScreen();
    void handleKeys();
    GameManager();
public:
    bool quit;
    void Update();
    static GameManager getInstance();
    void close();
};


#endif //TREFUSISENGINE_GAMEMANAGER_H
