//
// Created by elsa on 13.04.2020.
//

#include <iostream>
#include "GameManager.h"
#include "../objects/Character.h"
#include "Level.h"
#include "../trefusisInternals/TrefusisConfig.h"

GameManager* GameManager::game = nullptr;

void GameManager::trackObjects() {
    for (Character self : characters) {
        for (Character other : characters) {
            self.track(other);
        }
    }
}

bool inline GameManager::playerIsInsideMapAfterMove(float x, float y) {
    return player.x + x >= 0 && player.y + y >= 0 &&
            player.x + x <= Level::activeLevel.tileMatrix.size() &&
            player.y + y <= Level::activeLevel.tileMatrix.size();
}

bool inline GameManager::playerIsBlockedAfterMove(float dx, float dy) {
    //return Level::activeLevel.tileMatrix[player.x + dx][player.y + dy].height != 0;
    return false;
}

void GameManager::movePlayer(float x, float y) {
    if (playerIsInsideMapAfterMove(x, y) && !playerIsBlockedAfterMove(x, y)) {
        player.x += x;
        player.y += y;
    }
}

void GameManager::handleDialog() {
    if (displayDialog == false && DialogManager::hasNextDialog()) {
        displayDialog = true;
        currentDialog = DialogManager::nextDialog();
    }

    if (displayDialog == true) {
        std::cout << currentDialog.owner << ": " << currentDialog.text << "\n";
    }
}

void GameManager::handleKeys() {
    while(SDL_PollEvent(&e) != 0) {
        switch(e.type) {
            case SDL_QUIT:
                this->quit = true;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_UP) movePlayer(0, -1);
                else if (e.key.keysym.sym == SDLK_LEFT) movePlayer(-1, 0);
                else if (e.key.keysym.sym == SDLK_RIGHT) movePlayer(1, 0);
                else if (e.key.keysym.sym == SDLK_DOWN) movePlayer(0, 1);
                else if (e.key.keysym.sym == SDLK_RETURN) displayDialog = false;
        }
    }
}

void GameManager::Update() {
    this->handleKeys();
    this->handleDialog();
    TimeManager::tickTime();
    this->graphicsManager.drawScreen(player, this->currentDialog);
}

void GameManager::loadFirstScene() {
    player.x = 110;
    player.y = 110;
}

GameManager::GameManager() {
#ifdef DEBUG
    std::cout << "DEBUG: Instantiating GameManager\n";
#endif
    Level::importLevels();
    this->showSplashScreen();
    this->quit = false;
    this->loadFirstScene();
    this->harlequin.loadScript("SampleMap");
}

void GameManager::close() {
    this->graphicsManager.close();
}

void GameManager::showSplashScreen() {
    this->graphicsManager.drawToScreen((TrefusisConfig::prefix + TrefusisConfig::engineSplash).c_str(), true);
    SDL_Delay(2000);
    this->graphicsManager.drawToScreen((TrefusisConfig::prefix + TrefusisConfig::splash).c_str(), true);
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