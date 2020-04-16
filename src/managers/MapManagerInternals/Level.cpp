//
// Created by elsa on 14.04.2020.
//

#include <langinfo.h>
#include "Level.h"
#include "../../trefusisInternals/TrefusisConfig.h"

Level Level::activeLevel {};
std::vector<Level> Level::levels;


/**
 * Given the filename of a level, return the level's name, because C++ stdlib is lacking.
 * @param fileName filename of the level.
 * @return the level name.
 */
std::string parseLevelName(std::string fileName) {
    int pathEndIndex;
    int dotIndex;
    for (int i = 0; i < fileName.length(); i++) {
        if (fileName[i] == '.') {
            dotIndex = i;
        } else if (fileName[i] == '/') {
            pathEndIndex = i;
        }
    }
    std::string token = "";
    std::string levelName = "";
    for (int i = pathEndIndex + 1; i <= dotIndex; i++) {
        levelName += fileName[i];
    }
    return levelName;
}

Level Level::importLevelBase(std::string fileName) {
    FILE *file_ptr;
    Level newLevel {};
    newLevel.availableZones = Zone::importZones(parseLevelName(fileName));
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
                newLevel.zoneMatrix[row][column] = newLevel.availableZones[std::atoi(&toIndex)]; // Seriously fix this before prod.
                column++;
        }
    }
    fclose(file_ptr);
    return newLevel;
}

void Level::generateTiles() {
    for (int i = 0; i < 3600; i++) {
        for (int j = 0; j < 3600; j++) {
            this->tileMatrix[i][j] = this->zoneMatrix[i][j].generateTile();
        }
    }
}

void Level::importLevels() {
    for (auto fileName : TrefusisConfig::mapFileNames) {
        levels.push_back(importLevelBase(fileName));
    }
    activeLevel = levels[0];
}

void Level::changeLevel(int levelIndex) {
    activeLevel = levels[levelIndex];
}

Level::Level() {
    this->tileMatrix.resize(500);
    this->zoneMatrix.resize(500);
    for (int i = 0; i < 500; i++) {
        this->tileMatrix[i].push_back(EnviromentalActor(1));
        this->zoneMatrix[i].resize(500);
    }
}
