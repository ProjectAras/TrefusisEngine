//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_LEVEL_H
#define TREFUSISENGINE_LEVEL_H


#include "../../objects/EnviromentalActor.h"
#include "Zone.h"

class Level {
private:
    EnviromentalActor tileMatrix[3600][3600];
    Zone zoneMatrix[3600][3600];
    Zone availableZones[5];
    void importLevelBase(std::string fileName);
    void generateTiles();
};


#endif //TREFUSISENGINE_LEVEL_H
