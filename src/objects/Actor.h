//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_ACTOR_H
#define TREFUSISENGINE_ACTOR_H


#include <SDL2/SDL_render.h>

class Actor {
public:
    int x;
    int y;
    int objid;
    virtual SDL_Rect getTexture() = 0;
};


#endif //TREFUSISENGINE_ACTOR_H
