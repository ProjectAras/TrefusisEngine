//
// Created by sumut on 4/15/2020.
//

#include "FoilageGenerator.h"

std::vector<std::vector<foilageTile>>
FoilageGenerator::generateFoilage(vector <foilage> &foilages, int length, int width, int playerX, int playerY, int maxAllowed) {
    this->width = width;
    this->length = length;
    
    for(int i=0; i<width; i++) {
        for(int j=0; j<length; i++) {
            int foilageNumber = ((int)RandomNumberGenerator::random() * 100) % foilages.size();
            double chance = RandomNumberGenerator::random();
            foilageTile tile;

            if(foilages[foilageNumber].chance == chance) {
                tile.color = GREEN;
                tile.foilageId = foilages[foilageNumber].id;
            } else {
                tile.color = WHITE;
                tile.foilageId = -1;
            }

            field[i][j] = tile;
        }
    }
    FoilageGenerator::paint(playerX, playerY, BLUE, WHITE);

    for(int i=0; i<width; i++) {
        for(int j=0; j<length; j++) {
            if(field[i][j].color == WHITE) 
                if(FoilageGenerator::paint(i, j, WHITE, RED) <= maxAllowed)
                    FoilageGenerator::paint(i, j, RED, GREY);
        } 
    }
    return field;
}

int FoilageGenerator::paint(int x, int y, tileColor toBePainted, tileColor color) {
    field[x][y].color=color;
    int count;
    if(y != 0 && field[x][y-1].color == toBePainted) {
        count=1+count+FoilageGenerator::paint(x, y-1, toBePainted, color);
    }
    if(y != length-1 && field[x][y+1].color == toBePainted)
        count=1+count+FoilageGenerator::paint(x, y+1, toBePainted, color);
    if(x != 0 && field[x-1][y].color == toBePainted)
        count=1+count+FoilageGenerator::paint(x-1, y, toBePainted, color);
    if(x != width-1 && field[x+1][y].color == toBePainted)
        count=1+count+FoilageGenerator::paint(x+1, y, toBePainted, color);
    return count;
}