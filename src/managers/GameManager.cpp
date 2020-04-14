//
// Created by elsa on 13.04.2020.
//

#include "GameManager.h"
#include "../objects/Character.h"

void GameManager::trackObjects() {
    for (Character self : characters) {
        for (Character other : characters) {
            self.track(other);
        }
    }
}

void GameManager::handleKeys() {
    while(SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            this->quit = true;
            break;
        }
    }
}

void GameManager::Update() {
    this->handleKeys();
}

GameManager::GameManager() {
    this->showSplashScreen();
    this->quit = false;
}

void GameManager::close() {
    this->graphicsManager.close();
}
void GameManager::showSplashScreen() {
    this->graphicsManager.drawToScreen("../resources/splash.png");
}



