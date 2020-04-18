//
// Created by elsa on 14.04.2020.
//

#include "Zone.h"
#include "../../trefusisInternals/RandomNumberGenerator.h"
#include "../../trefusisInternals/TrefusisConfig.h"


/**
void mallocZoneProbability(zoneProbability* zp, int mallocSize) {
    zp->ids = (int*) malloc(sizeof(int ) * mallocSize);
    zp->lowerBounds = (double*) malloc(sizeof(double ) * mallocSize);
    zp->higherBounds = (double *) malloc(sizeof(double ) * mallocSize);
}
*/
/**
 * Determine the count of tiles in a given zone file.
 * @param fileName The count of tiles in a zone file.
 * @return the number of tiles in the zone file.
 */
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

Zone::Zone() = default;

Zone Zone::importZone(std::string fileName) {
    int tileCount = determineEnviromentCount(fileName);
    Zone newZone {};
    FILE* fileptr;
    fileptr = fopen(fileName.c_str(), "r");
    std::string token;
    int traversingChar = ' ';
    float currentProbability = 0;
    float totalProbability = 0;
    while (traversingChar != EOF) {
        traversingChar = fgetc(fileptr);
        switch (traversingChar) {
            case ',':
                newZone.tileSpawnProbability.ids.push_back(std::atoi(token.c_str()));
//                newZone.tileSpawnProbability.ids++;
                token = "";
                break;
            case '\n':
                totalProbability += std::atof(token.c_str());
                newZone.tileSpawnProbability.lowerBounds.push_back(currentProbability);
                newZone.tileSpawnProbability.higherBounds.push_back(totalProbability);
//                newZone.tileSpawnProbability.higherBounds++;
//                newZone.tileSpawnProbability.lowerBounds++;
                currentProbability += std::atof(token.c_str());
                token = "";
                break;
            case ' ':
                continue;
            default:
                token += traversingChar;
                break;
        }
    }
    newZone.tileCount = tileCount;
    return newZone;
}


/**
 * Generate the name of the file holding a zone.
 * @param levelName Name of the level zone is in.
 * @param zoneIndex Index of the level zone is in.
 * @return The generated filename.
 */
std::string inline generateZoneFileName(std::string levelName, int zoneIndex) {
    return TrefusisConfig::prefix + TrefusisConfig::mapsDirectory + levelName + "." + std::to_string(zoneIndex);
}

/**
 * Get the number of zone files for a given level.
 * @param levelName
 * @return
 */
int getZoneFileCount(std::string levelName) {
#ifdef DEBUG
    std::cout<< "Checking zone count for: " << levelName << "\n";
#endif
    int fileCount = -1;
    FILE* fileptr;
    do {
        fileCount++;
        fileptr = fopen(generateZoneFileName(levelName, fileCount).c_str(), "r");
        if (fileptr != NULL) {
            fclose(fileptr);
        }
    } while(fileptr != NULL);
    return fileCount;
}

void copyZoneProbabilities(zoneProbability* self, zoneProbability* other) {
    for (int i = 0; i < other->ids.size(); i++) {
        if (i > self->ids.size()) {
            self->ids.push_back(other->ids[i]);
        } else {
            self->ids[i] = other->ids[i];
        }

        if (i > self->lowerBounds.size()) {
            self->lowerBounds.push_back(other->lowerBounds[i]);
        } else {
            self->lowerBounds[i] = other->lowerBounds[i];
        }

        if (i > self->higherBounds.size()) {
            self->higherBounds.push_back(other->higherBounds[i]);
        } else {
            self->higherBounds[i] = other->higherBounds[i];
        }
    }
}

std::vector<Zone> Zone::importZones(std::string levelName) {
#ifdef DEBUG
    std::cout << "Importing from " << levelName << "\n";
#endif
    int zoneCount = getZoneFileCount(levelName);
#ifdef DEBUG
    std::cout << "Zone count: " << zoneCount << "\n";
#endif
    std::vector<Zone> zoneArray;
    std::string fileName;
    // We start looping through, and we constantly reallocating the memory.
    for (int i = 0; i < zoneCount; i++) {
#ifdef DEBUG
        std::cout << "Importing zone " << i << "\n";
#endif
        fileName = generateZoneFileName(levelName, i);
        Zone newZone = importZone(fileName);
        zoneArray.push_back(newZone);
    }
    return zoneArray;
}

EnviromentalActor Zone::generateTile() {
    float randomNumber = RandomNumberGenerator::random();
    for (int i = 0; i < this->tileSpawnProbability.ids.size(); i++) {
        if (this->tileSpawnProbability.lowerBounds[i] <= randomNumber
        && randomNumber < this->tileSpawnProbability.higherBounds[i]) {
            EnviromentalActor enviromentalActor {this->tileSpawnProbability.ids[i]};
            return enviromentalActor;
        }
    }
    return NULL;
}

void vector_copy(std::vector<int> *self, std::vector<int> *other) {
    for (auto obj : *other) {
        self->push_back(obj);
    }
}

void vector_copy(std::vector<double> *self, std::vector<double> *other) {
    for (auto obj : *other) {
        self->push_back(obj);
    }
}

void Zone::copyProbabilities(Zone *otherZone) {
    vector_copy(&this->tileSpawnProbability.ids, &otherZone->tileSpawnProbability.ids);
    vector_copy(&this->tileSpawnProbability.lowerBounds, &otherZone->tileSpawnProbability.lowerBounds);
    vector_copy(&this->tileSpawnProbability.higherBounds, &otherZone->tileSpawnProbability.higherBounds);
}

void Zone::operator=(const Zone &z) {
    copyProbabilities((Zone *) &z);
    this->tileCount = z.tileCount;
}