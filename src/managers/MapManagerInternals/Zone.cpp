//
// Created by elsa on 14.04.2020.
//

#include "Zone.h"


void mallocZoneProbability(zoneProbability* zp, int mallocSize) {
    zp->ids = (int*) malloc(sizeof(int ) * mallocSize);
    zp->lowerBounds = (double*) malloc(sizeof(double ) * mallocSize);
    zp->higherBounds = (double *) malloc(sizeof(double ) * mallocSize);
}

int determineEnviromentCount(const std::string& fileName) {
    FILE* fileptr;
    fileptr = fopen(fileName.c_str(), "r");
    int char_ = ' ';
    int lineCount = -1; // Offset of EOF \n.
    while (char_ != EOF) {
        char_ = fgetc(fileptr);
        if (char_ == '\n') {
            lineCount++;
        }
    }
    fclose(fileptr);
    return lineCount;
}

Zone::Zone(int tileCount) {
    zoneProbability* zpptr;
    mallocZoneProbability(zpptr, tileCount);
    this->tileSpawnProbability = *zpptr;
}

Zone Zone::importZone(std::string fileName) {
    int tileCount = determineEnviromentCount(fileName);
    Zone newZone {tileCount};
    FILE* fileptr;
    fileptr = fopen(fileName.c_str(), "r");
    std::string token;
    int traversingChar = ' ';
    int currentProbability = 0;
    int totalProbability = 0;
    while (traversingChar != EOF) {
        traversingChar = fgetc(fileptr);
        switch (traversingChar) {
            case ',':
                *newZone.tileSpawnProbability.ids = std::atoi(token.c_str());
                newZone.tileSpawnProbability.ids++;
                token = "";
                break;
            case '\n':
                totalProbability += std::atof(token.c_str());
                *newZone.tileSpawnProbability.lowerBounds = currentProbability;
                *newZone.tileSpawnProbability.higherBounds = totalProbability;
                newZone.tileSpawnProbability.higherBounds++;
                newZone.tileSpawnProbability.lowerBounds++;
                currentProbability += std::atof(token.c_str());
                break;
            case ' ':
                continue;
            default:
                token += traversingChar;
                break;
        }
    }
    return newZone;
}

/**
 * Get the number of zone files for a given level.
 * @param levelName
 * @return
 */
int getZoneFileCount(std::string levelName) {
    int fileCount = -1;
    FILE* fileptr;
    do {
        fileCount++;
        fileptr = fopen((levelName + "." + std::to_string(fileCount)).c_str(), "r");
        fclose(fileptr);
    } while(fileptr != NULL);
    return fileCount;
}

Zone* Zone::importZones(std::string levelName) {
    int zoneCount = getZoneFileCount(levelName);
    Zone zoneArray[zoneCount] {};
}