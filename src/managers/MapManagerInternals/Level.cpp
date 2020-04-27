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

void Level::importLevelZoneMatrix(levelProbability *lpp) {
    FILE* fptr;
    fptr = fopen((TrefusisConfig::prefix + TrefusisConfig::mapsDirectory + lpp->levelName).c_str(), "r");
    lpp->zoneMatrix.resize(500);
    int i = 0;
    int j = 0;
    std::string token;
    int char_;
    do {
        char_ = fgetc(fptr);
        switch (char_) {
            case '\n':
                lpp->zoneMatrix[i][j] = std::atoi(token.c_str());  // Assign last zone of a row.
                i++;
            case ' ':
                break;
            case ',':
                lpp->zoneMatrix[i][j] = std::atoi(token.c_str()); // Assign zone.
                j++;
                break;
            case EOF:
                break;
            default:
                token += char_;
        }
    } while (char_ != EOF);
}

void Level::importLevelProbabilities(levelProbabilities* lp, const char* fileName) {
    FILE* fptr;
    fptr = fopen(fileName, "r");
    std::string token;
    ReadingMode mode;
    envActor* currentEv;
    do {
        int char_ = fgetc(fptr);
        switch(char_) {
            case '+':
                mode = LEVEL;
                break;
            case '-':
                mode = ZONE;
                break;
            case '*':
                currentEv = new envActor();
                mode = TILE;
                break;
            case '/':
                currentEv = new envActor();
                mode = FOILAGE;
                break;
            case '\n':
                switch (mode) {
                    case LEVEL:
                        lp->levelCount += 1;
                        lp->levelNames.push_back(token);
                        lp->probabilities.push_back(levelProbability{});
                        lp->probabilities.back().levelName = token.c_str();
                        importLevelZoneMatrix(&lp->probabilities.back());
                        break;
                    case ZONE:
                        lp->probabilities.back().zoneCount += 1;
                        lp->probabilities.back().zoneProbabilities;
                }
            default:
                token += char_;
                break;
        }
    }
}

levelProbabilities Level::importLevels() {
    levelProbabilities lp;
    importLevelProbabilities(&lp, TrefusisConfig::levelsLocation.c_str());
    activeLevel = levels[0];
}

void Level::changeLevel(int levelIndex) {
    activeLevel = levels[levelIndex];
}

Level::Level() {
#ifdef DEBUG
    std::cout << "Generating level...\n";
#endif
}
