//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_ENVIROMENTALACTOR_H
#define TREFUSISENGINE_ENVIROMENTALACTOR_H

#include <string>
#include <SDL2/SDL_render.h>
#include "Actor.h"


class EnviromentalActor : Actor {
private:
    int id;
    int timeSetting;
    int isDay;  // 1 if day, -1 if night
public:
    SDL_Rect getTexture();
    void incrementSeason();
    void transitionDayNight();
    EnviromentalActor(int id);
    EnviromentalActor();
    void operator= (const EnviromentalActor &e);
};


#endif //TREFUSISENGINE_ENVIROMENTALACTOR_H
