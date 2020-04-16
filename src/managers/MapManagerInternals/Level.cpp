//
// Created by elsa on 14.04.2020.
//

#include <langinfo.h>
#include "Level.h"

Level* Level::activeLevel = nullptr;
Level* Level::levels = nullptr;


/**
 * Given the filename of a level, return the level's name, because C++ stdlib is lacking.
 * @param fileName filename of the level.
 * @return the level name.
 */
std::string parseLevelName(std::string fileName) {
    int dotIndex;
    for (int i = 0; i < fileName.length(); i++) {
        if (fileName[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    std::string token = "";
    std::string levelName = "";
    for (int i = 0; i <= dotIndex; i++) {
        levelName += fileName[i];
    }
    return levelName;
}

Level Level::importLevelBase(std::string fileName) {
    FILE *file_ptr;
    Level* newLevel {};
    newLevel-> availableZones = Zone::importZones(parseLevelName(fileName));
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
                newLevel->zoneMatrix[row][column] = newLevel->availableZones[std::atoi(&toIndex)]; // Seriously fix this before prod.
                column++;
        }
    }
    fclose(file_ptr);
    return *newLevel;
}

void Level::generateTiles() {
    for (int i = 0; i < 3600; i++) {
        for (int j = 0; j < 3600; j++) {
            this->tileMatrix[i][j] = this->zoneMatrix[i][j].generateTile();
        }
    }
}

void Level::importLevels(std::vector<std::string> mapNames) {
    levels = (Level*) malloc(sizeof(Level) * mapNames.size());
    for (auto fileName : mapNames) {
        *levels = importLevelBase(fileName);
        levels++;
    }
    levels -= mapNames.size();
    activeLevel = levels;
}

void Level::changeLevel(int levelIndex) {
    activeLevel = &levels[levelIndex];
}