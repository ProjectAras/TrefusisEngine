//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_ZONE_H
#define TREFUSISENGINE_ZONE_H


#include "../../objects/EnviromentalActor.h"
#include <iostream>
#include <string>

struct foilage {
    int id; //id of the foilage object
    int chance; //chance of the foilage object, this variable may be different for different zones
};

class Zone {
public:
    EnviromentalActor generateTile();
};


#endif //TREFUSISENGINE_ZONE_H
