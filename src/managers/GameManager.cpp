//
// Created by elsa on 13.04.2020.
//

#include "GameManager.h"
#include "../objects/Character.h"
#include "MapManagerInternals/Level.h"

GameManager* GameManager::game = nullptr;

void GameManager::trackObjects() {
    for (Character self : characters) {
        for (Character other : characters) {
            self.track(other);
        }
    }
}

void GameManager::handleKeys() {
    while(SDL_PollEvent(&e) != 0) {
        switch(e.type) {
            case SDL_QUIT:
                this->quit = true;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_UP) player.y--;
                else if (e.key.keysym.sym == SDLK_LEFT) player.x--;
                else if (e.key.keysym.sym == SDLK_RIGHT) player.x++;
                else if (e.key.keysym.sym == SDLK_DOWN) player.y++;
        }
    }
}

void GameManager::Update() {
    this->handleKeys();
    this->graphicsManager.drawScreen(player);
}

void GameManager::loadFirstScene() {
    player.x = 110;
    player.y = 110;
}

GameManager::GameManager() {
    Level::importLevels();
    this->showSplashScreen();
    this->quit = false;
    this->loadFirstScene();
}

void GameManager::close() {
    this->graphicsManager.close();
}
void GameManager::showSplashScreen() {
    this->graphicsManager.drawToScreen("../resources/splash.png", true);
    SDL_Delay(2000);
    this->graphicsManager.drawToScreen("../resources/game_splash.png", true);
    SDL_Delay(2000);
}

GameManager GameManager::getInstance() {
    if (game != nullptr) {
        return *game;
    } else {
        game = new GameManager();
        return *game;
    }
}