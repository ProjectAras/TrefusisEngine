//
// Created by elsa on 14.04.2020.
//

#ifndef TREFUSISENGINE_LEVEL_H
#define TREFUSISENGINE_LEVEL_H


#include <vector>
#include "../../objects/EnviromentalActor.h"

struct envActor {
    int id;
    int width;
    int height;
};

struct zoneProbability {
    int tileCount;
    int foilageCount;
    std::vector<double> tileChances;
    std::vector<double> foilageChances;
    std::vector<envActor> tiles;
    std::vector<envActor> foilages;
};

struct levelProbability {
    const char* levelName;
    std::vector<std::vector<int>> zoneMatrix;
    int zoneCount;
    std::vector<zoneProbability> zoneProbabilities;
};

struct levelProbabilities {
    int levelCount;
    std::string levelNames;
    std::vector<levelProbability> levelProbabilities;
};


class Level {
private:
    Level();
    std::vector<std::vector<EnviromentalActor>> foilageMatrix;
    static std::vector<Level> levels;
    std::vector<Zone> availableZones;
    FoilageGenerator foilageGenerator;
    
    /**
     * Import the base levelmap.
     * @param fileName File of the level.
     * @return the level map.
     */
    static Level importLevelBase(std::string fileName);
    void generateTiles();
    void smoothTiles();
    void generateFoilages();
public:
    std::vector<std::vector<EnviromentalActor>> tileMatrix;
    static Level activeLevel;
    /**
     * Given a vector of level names, import the levels.
     * @return the level probabilities object.
     */
    static levelProbabilities importLevels();
    /**
     * Change the active level
     * @param levelIndex New active level's index.
     */
    static void changeLevel(int levelIndex);
};


#endif //TREFUSISENGINE_LEVEL_H
