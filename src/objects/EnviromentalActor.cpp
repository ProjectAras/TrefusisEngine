//
// Created by elsa on 13.04.2020.
//

#include "EnviromentalActor.h"

#include <utility>

void EnviromentalActor::incrementSeason() {
    this->texturePointer+=2;
}

void EnviromentalActor::transitionDayNight() {
    this->texturePointer += this->isDay;
    this->isDay *= -1;
}

SDL_Texture* EnviromentalActor::getTexture() {
    return this->textures[texturePointer];
}

EnviromentalActor::EnviromentalActor(std::string fileName) {
//    EnviromentalActor importedActor = importEnviromentalActor(std::move(fileName));
    this->texturePointer = 0;
    this->isDay = 1;
//    for (int i = 0; i < 8; i++) {
//        this->textures[i] = importedActor.textures[i];
//    }
}