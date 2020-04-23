//
// Created by sumut on 4/15/2020.
//

#include "FoilageGenerator.h"

std::vector<std::vector<EnviromentalActor>>
FoilageGenerator::generateFoilage(foilageProbability foilages, int length, int width, int playerX, int playerY,
                                  int maxAllowed) {
    this->width = width;
    this->length = length;

    std::vector<std::vector<foilageTile>> field(width);

    for (int i = 0; i < width; i++) {
        field[i].resize(length);

        for (int j = 0; j < length; j++) {
            int foilageNumber = (int) (RandomNumberGenerator::random() * 100) % foilages.ids.size();
            double number = RandomNumberGenerator::random();
            foilageTile tile;

            if (foilages.ids[foilageNumber] >= number) {
                tile.color = GREEN;
                tile.foilageId = foilages.ids[foilageNumber];
            } else {
                tile.color = WHITE;
                tile.foilageId = -1;
            }

            field[i][j] = tile;
        }
    }

    FoilageGenerator::paint(playerX, playerY, BLUE, WHITE);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (field[i][j].color == WHITE)
                if (FoilageGenerator::paint(i, j, WHITE, RED) <= maxAllowed)
                    FoilageGenerator::paint(i, j, RED, GREY);
        }
    }

    if (isContains(RED)) {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (field[i][j].color == GREEN && isRemovable(i, j)) {
                    field[i][j].foilageId = -1;
                    paint(i, j, BLUE, RED);
                    paint(i, j, BLUE, GREY);
                }
            }
        }
        if (isContains(RED))
            return generateFoilage(foilages, length, width, playerX, playerY, maxAllowed);
    }

    std::vector<std::vector<EnviromentalActor>> actors(width);

    for (int i = 0; i < width; i++)
        actors[i].resize(length);

    for(int i=0; i<field.size(); i++) {
        for(int j=0; j<field[0].size(); j++) {
            EnviromentalActor enviromentalActor {this->field[i][j].foilageId};
        }
    }

    return actors;
}

bool FoilageGenerator::isContains(tileColor color) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (field[i][j].color == color)
                return true;
        }
    }
    return false;
}

bool FoilageGenerator::isRemovable(int x, int y) {
    bool blueAdjacent = false;
    bool redAdjacent = false;

    if (field[x][y - 1].color == BLUE)
        blueAdjacent = true;
    else if (field[x][y - 1].color == RED)
        redAdjacent = true;
    if (field[x][y + 1].color == BLUE)
        blueAdjacent = true;
    else if (field[x][y + 1].color == RED)
        redAdjacent = true;
    if (field[x - 1][y].color == BLUE)
        blueAdjacent = true;
    else if (field[x - 1][y].color == RED)
        redAdjacent = true;
    if (field[x + 1][y].color == BLUE)
        blueAdjacent = true;
    else if (field[x + 1][y].color == RED)
        redAdjacent = true;

    return blueAdjacent && redAdjacent;
}

int FoilageGenerator::paint(int x, int y, tileColor toBePainted, tileColor color) {
    field[x][y].color = color;
    int count;
    if (y != 0 && field[x][y - 1].color == toBePainted) {
        count = 1 + count + FoilageGenerator::paint(x, y - 1, toBePainted, color);
    }
    if (y != length - 1 && field[x][y + 1].color == toBePainted)
        count = 1 + count + FoilageGenerator::paint(x, y + 1, toBePainted, color);
    if (x != 0 && field[x - 1][y].color == toBePainted)
        count = 1 + count + FoilageGenerator::paint(x - 1, y, toBePainted, color);
    if (x != width - 1 && field[x + 1][y].color == toBePainted)
        count = 1 + count + FoilageGenerator::paint(x + 1, y, toBePainted, color);
    return count;
}