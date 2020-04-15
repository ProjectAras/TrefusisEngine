//
// Created by elsa on 13.04.2020.
//

#include "EnviromentalActor.h"
#include "../trefusisInternals/TrefusisConfig.h"

#include <utility>

void EnviromentalActor::incrementSeason() {
    this->timeSetting+=2;
}

void EnviromentalActor::transitionDayNight() {
    this->timeSetting += this->isDay;
    this->isDay *= -1;
}

SDL_Rect* EnviromentalActor::getTexture() {
    SDL_Rect* rect;
    rect->h = TrefusisConfig::tileSize;
    rect->w = TrefusisConfig::tileSize;
    rect->y = TrefusisConfig::tileSize * this->id;
    rect->x = TrefusisConfig::tileSize * this->timeSetting;
}

EnviromentalActor::EnviromentalActor() {
//    EnviromentalActor importedActor = importEnviromentalActor(std::move(fileName));
    this->isDay = 1;
//    for (int i = 0; i < 8; i++) {
//        this->textures[i] = importedActor.textures[i];
//    }
}

void EnviromentalActor::importEnviromentalActors() {

}