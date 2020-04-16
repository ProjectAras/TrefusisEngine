//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_ZONE_H
#define TREFUSISENGINE_ZONE_H


#include "../../objects/EnviromentalActor.h"
#include <iostream>
#include <string>

/**
 * A zone's probabilities for tile generation.
 */
struct zoneProbability {
    int* ids;
    double* lowerBounds;
    double* higherBounds;
};

/**
 * Allocate memory for a zone probability structure.
 * @param zp ZP pointer.
 * @param mallocSize Memory allocation multiplier.
 */
void mallocZoneProbability(zoneProbability* zp, int mallocSize);

struct foilage {
    int id; //id of the foilage object
    int chance; //chance of the foilage object, this variable may be different for different zones
};

class Zone {
private:
    zoneProbability tileSpawnProbability;
    static Zone importZone(std::string fileName);
public:
    EnviromentalActor generateTile();
    static Zone* importZones(std::string levelName);
    Zone(int tileCount);
};


#endif //TREFUSISENGINE_ZONE_H
