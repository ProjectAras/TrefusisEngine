//
// Created by elsa on 14.04.2020.
//

#include <langinfo.h>
#include "Level.h"
#include "../../trefusisInternals/TrefusisConfig.h"
#include "../../trefusisInternals/RandomNumberGenerator.h"

#ifdef DEBUG
#include <iostream>
#endif
Level Level::activeLevel {};
std::vector<Level> Level::levels;


/**
 * Given the filename of a level, return the level's name, because C++ stdlib is lacking.
 * @param fileName filename of the level.
 * @return the level name.
 */
std::string parseLevelName(std::string fileName) {
    int pathEndIndex = 0;
    int dotIndex = -1;
    for (int i = 0; i < fileName.length(); i++) {
        if (fileName[i] == '.') {
            dotIndex = i;
        } else if (fileName[i] == '/') {
            pathEndIndex = i;
        }
    }
    std::string token = "";
    std::string levelName = "";
    for (int i = pathEndIndex + 1; i < dotIndex; i++) {
        levelName += fileName[i];
    }
#ifdef DEBUG
    std::cout << "Level Name: " << levelName << "\n";
#endif
    return levelName;
}

Level Level::importLevelBase(std::string fileName) {
    FILE *file_ptr;
#ifdef DEBUG
    std::cout << "File name: " << fileName << "\n";
#endif
    Level newLevel {};
    newLevel.availableZones = Zone::importZones(parseLevelName(fileName));
    file_ptr = fopen(fileName.c_str(), "r");
    if (file_ptr == NULL) {
        std::cout << "Error, file could not be opened\n";
    }
    int row = 0;
    int column = 0;
    int token = 66;
    while (token != EOF) {
        token = fgetc(file_ptr);
        switch (token) {
            case '\n':
                row++;
                column = 0;
                break;
            case ',':
                column++;
            case ' ':
            case EOF:
                continue;
            default:
                const char toIndex = token; // This is a terrible idea use negation instead.
                newLevel.zoneMatrix[row][column] = newLevel.availableZones[std::atoi(&toIndex)]; // Seriously fix this before prod.
        }
    }
    fclose(file_ptr);
    newLevel.generateTiles();
    newLevel.smoothTiles();
    return newLevel;
}

void Level::generateTiles() {

    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            this->tileMatrix[i][j] = this->zoneMatrix[i][j].generateTile();
        }
    }
}

void Level::generateFoilages() {
    
}

void Level::smoothTiles() {
    std::vector<EnviromentalActor> surrounding;
    for (int i = 1; i < 499; i++) {
        for (int j = 1; j < 499; j++ ) {
            surrounding.push_back(this->tileMatrix[i - 1][j]);
            surrounding.push_back(this->tileMatrix[i][j - 1]);
            surrounding.push_back(this->tileMatrix[i + 1][j]);
            surrounding.push_back(this->tileMatrix[i][j + 1]);
            this->tileMatrix[i][j] = surrounding[RandomNumberGenerator::randint(0, 4)];
            surrounding.clear();
        }
    }

}

void Level::importLevels() {
    for (auto fileName : TrefusisConfig::mapFileNames) {
        levels.push_back(importLevelBase(TrefusisConfig::prefix + TrefusisConfig::mapsDirectory + fileName));
    }
    activeLevel = levels[0];
}

void Level::changeLevel(int levelIndex) {
    activeLevel = levels[levelIndex];
}

Level::Level() {
#ifdef DEBUG
    std::cout << "Generating level...\n";
#endif
    this->tileMatrix.resize(500);
    this->zoneMatrix.resize(500);
    for (int i = 0; i < 500; i++) {
        this->tileMatrix[i].resize(500);
        this->zoneMatrix[i].resize(500);
    }
}
