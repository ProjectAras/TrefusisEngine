//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_LEVEL_H
#define TREFUSISENGINE_LEVEL_H


#include <vector>
#include "../../objects/EnviromentalActor.h"
#include "Zone.h"

class Level {
private:
    Zone zoneMatrix[500][500];
    static Level* levels;
    Zone* availableZones;
    /**
     * Import the base levelmap.
     * @param fileName File of the level.
     * @return the level map.
     */
    static Level importLevelBase(std::string fileName);
    void generateTiles();
public:
    EnviromentalActor tileMatrix[500][500];
    static Level* activeLevel;
    /**
     * Given a vector of level names, import the levels.
     * @param mapNames Names of the maps.
     */
    static void importLevels(std::vector<std::string> mapNames);
    static void changeLevel(int levelIndex);
};


#endif //TREFUSISENGINE_LEVEL_H
