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

bool inline GameManager::playerIsInsideMapAfterMove(int x, int y) {
    return player.x + x >= 0 && player.y + y >= 0 &&
            player.x + x <= Level::activeLevel.tileMatrix.size() &&
            player.y + y <= Level::activeLevel.tileMatrix.size();
}

void GameManager::movePlayer(int x, int y) {
    if (playerIsInsideMapAfterMove(x, y) && !Level::activeLevel.tileMatrix[player.x + x][player.y + y].isObstruction) {
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
    this->graphicsManager.drawScreen(player, this->currentDialog);
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
    this->harlequin.loadScript("SampleMap");
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