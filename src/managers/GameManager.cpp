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

void GameManager::Update() {
}

GameManager::GameManager() {
    auto* gm = new GraphicsManager(640, 320);
    this->graphicsManager = *gm;
}

GameManager::ShowSplashScreen() {

}



