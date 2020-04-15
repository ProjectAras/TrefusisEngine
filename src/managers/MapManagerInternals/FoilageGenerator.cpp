//
// Created by sumut on 4/15/2020.
//

#include "FoilageGenerator.h"

using namespace std;

vector <vector<foilage>>
generateFoilage(vector <foilage> &foilages, int length, int width, int playerX, int playerY, int maxAllowed) {
    this->length=length;
    this->width=width;
    while (true) {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                foilageTile tile;
                int foilageNumber = (rand() % (foilages.size() + 1));

                if (i == playerX && j == playerY) {
                    tile.foilageId = -1;
                    tile.color = BLUE;
                } else if ((rand() % 101) <= foilages[foilageNumber].chance * 100) {
                    tile.foilageId = foilages[foilageNumber].id;
                    tile.color = GREEN;
                } else {
                    tile.foilageId = -1;
                    tile.color = WHITE;
                }

                field[i][j] = tile;
            }
        }
        break;
    }
}

void walk(int x, int y) {

}