//
// Created by sumut on 4/15/2020.
//

#ifndef TREFUSISENGINE_FOILAGEGENERATOR_H
#define TREFUSISENGINE_FOILAGEGENERATOR_H

#include "Zone.h"
#include "../../trefusisInternals/RandomNumberGenerator.h"
#include "../../objects/EnviromentalActor.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/**
 * Used only when generating foilages..
 */
enum tileColor {
    BLUE, GREEN, RED, GREY, WHITE
};

/**
 * A struct to hold color and foilage id.
 */
struct foilageTile {
    tileColor color;
    int foilageId;
};


class FoilageGenerator {
public:
    /**
     * Generates foilage and returns a two dimensional vector.
     * @param foilages Foilage object that holds ids and probabilities.
     * @param length Length of the area.
     * @param width Width of the area.
     * @param playerX X coordinate of the player.
     * @param playerY Y coordinate of the player.
     * @param maxAllowed Maximum allowed blocked-off area.
     * @return A two dimensional vector of EnviromentalActor.
     */
    std::vector<std::vector<EnviromentalActor>>
    generateFoilage(foilageProbability foilages, int length, int width, int playerX, int playerY, int maxAllowed);

private:
    /**
     * A recursive function to paint tiles.
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param toBePainted The color of the tiles to be painted.
     * @param color Color to paint.
     * @return Number of tile that painted.
     */
    int paint(int x, int y, tileColor toBePainted, tileColor color);

    /**
     * TO check if there any tile in the specified color.
     * @param color Specified color.
     * @return Returns true if it contains any tile in the specified color, otherwise returns false.
     */
    bool isContains (tileColor color);

    /**
     * To check is foilage in the coordinates x and y removable.
     * @param x X coordinate of the foilageç
     * @param y Y coordinate of the foilage.
     * @return Returns true if it is removable otherwise returns false.
     */
    bool isRemovable(int x, int y);

    std::vector<std::vector<foilageTile>> field;
    int length;
    int width;
};


#endif //TREFUSISENGINE_FOILAGEGENERATOR_H