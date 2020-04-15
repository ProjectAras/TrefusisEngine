//
// Created by sumut on 4/15/2020.
//

#ifndef TREFUSISENGINE_FOILAGEGENERATOR_H
#define TREFUSISENGINE_FOILAGEGENERATOR_H

#include "Zone.h"

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
    vector <vector<foilage>>
    generateFoilage(vector <foilage> &foilages, int length, int width, int playerX, int playerY);
private:
    vector<vector<foilageTile>> field;
    int length;
    int width;
};


#endif //TREFUSISENGINE_FOILAGEGENERATOR_H
