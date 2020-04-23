//
// Created by umut on 23.04.2020.
//

#include "FoilageManager.hpp"


std::vector<std::vector<EnviromentalActor>> FoilageManager::generateFoilage(int length, int width, int playerX, int playerY, int maxAllowed) {
    return foilageGenerator.generateFoilage(foilageSpawnProbability, length, width, playerX, playerY, maxAllowed);
}
