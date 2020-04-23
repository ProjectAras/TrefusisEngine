//
// Created by umut on 23.04.2020.
//

#ifndef TREFUSISENGINE_FOILAGEMANAGER_HPP
#define TREFUSISENGINE_FOILAGEMANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "FoilageGenerator.h"
#include "../../objects/EnviromentalActor.h"


/**
 * A zone's probabilities for foilage generation.
 */
struct foilageProbability {
    std::vector<int> ids{}; // IDs of the foilages.
    std::vector<double> probabilities{}; // Spawn probability of the foilages.
};

class FoilageManager {
private:
    foilageProbability foilageSpawnProbability;
    FoilageGenerator foilageGenerator;

public:
    std::vector<std::vector<EnviromentalActor>> generateFoilage(int length, int width, int playerX, int playerY, int maxAllowed);
};


#endif //TREFUSISENGINE_FOILAGEMANAGER_HPP
