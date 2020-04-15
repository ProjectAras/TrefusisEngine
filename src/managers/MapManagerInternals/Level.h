//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_LEVEL_H
#define TREFUSISENGINE_LEVEL_H


#include "../../objects/EnviromentalActor.h"
#include "Zone.h"

class Level {
private:
    Zone zoneMatrix[500][500]{};
    Zone availableZones[5]{};
    void importLevelBase(std::string fileName);
    void generateTiles();
public:
    EnviromentalActor tileMatrix[500][500];
};


#endif //TREFUSISENGINE_LEVEL_H
