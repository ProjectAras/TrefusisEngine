//
// Created by elsa on 14.04.2020.
//

#include "Level.h"


void Level::importLevelBase(std::string fileName) {
    FILE *file_ptr;
    file_ptr = fopen(fileName.c_str(), "r");
    int row = 0;
    int column = 0;
    int token = 65;
    while (token != EOF) {
        token = fgetc(file_ptr);
        switch (token) {
            case '\n':
                row++;
                column = 0;
                break;
            case ',':
            case ' ':
                continue;
            default:
                const char toIndex = token; // This is a terrible idea use negation instead.
                this->zoneMatrix[row][column] = availableZones[std::atoi(&toIndex)]; // Seriously fix this before prod.
                column++;
        }
    }
}

void Level::generateTiles() {
    for (int i = 0; i < 3600; i++) {
        for (int j = 0; j < 3600; j++) {
            this->tileMatrix[i][j] = this->zoneMatrix[i][j].generateTile();
        }
    }
}