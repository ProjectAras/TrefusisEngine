//
// Created by sumut on 4/15/2020.
//

#ifndef TREFUSISENGINE_FOILAGEGENERATOR_H
#define TREFUSISENGINE_FOILAGEGENERATOR_H

#include "Zone.h"
#include "../../trefusisInternals/RandomNumberGenerator.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

enum tileColor {
    BLUE, GREEN, RED, GREY, WHITE
};

struct foilageTile {
    tileColor color;
    int foilageId;
};

class FoilageGenerator {
public:
    std::vector<std::vector<foilageTile>>
    generateFoilage(vector <foilage> &foilages, int length, int width, int playerX, int playerY, int maxAllowed);

    int paint(int x, int y, tileColor toBePainted, tileColor color);
private:
    std::vector<std::vector<foilageTile>> field;
    int length;
    int width;
};


#endif //TREFUSISENGINE_FOILAGEGENERATOR_H
