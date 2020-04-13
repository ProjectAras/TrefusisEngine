//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_ENVIROMENTALACTOR_H
#define TREFUSISENGINE_ENVIROMENTALACTOR_H

#include <SDL_render.h>
#include <string>
#include "Actor.h"

class EnviromentalActor : Actor {
private:
    SDL_Texture* textures[8]{};
    int texturePointer;
    int isDay;  // 1 if day, -1 if night
public:
    SDL_Texture* getTexture() override;
    void incrementSeason();
    void transitionDayNight();
    EnviromentalActor(std::string fileName);
};


#endif //TREFUSISENGINE_ENVIROMENTALACTOR_H
