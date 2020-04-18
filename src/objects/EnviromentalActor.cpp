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

SDL_Rect EnviromentalActor::getTexture() {
    SDL_Rect rect;
    rect.h = TrefusisConfig::tileSize;
    rect.w = TrefusisConfig::tileSize;
    rect.y = TrefusisConfig::tileSize * this->id;
    rect.x = TrefusisConfig::tileSize * this->timeSetting;
    return rect;
}

EnviromentalActor::EnviromentalActor(int id) {
    this->timeSetting = 0;
    this->id = id;
    this->isDay = 1;
}

EnviromentalActor::EnviromentalActor() {
    this->timeSetting = 0;
    this->id = 0;
    this->isDay = 1;
    this->x = 0;
    this->y = 0;
}

void EnviromentalActor::operator=(const EnviromentalActor &e) {
    this->id = e.id;
}
