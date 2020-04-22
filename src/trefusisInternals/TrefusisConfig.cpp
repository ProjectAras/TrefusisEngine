//
// Created by elsa on 15.04.2020.
//

#include <vector>
#include "TrefusisConfig.h"

std::string TrefusisConfig::configFile;
std::string TrefusisConfig::tilemapLocation;
std::string  TrefusisConfig::mapsDirectory;
std::string  TrefusisConfig::resourcesDirectory;
std::string  TrefusisConfig::musicsDirectory;
std::vector<std::string> TrefusisConfig::mapFileNames;
const char* TrefusisConfig::scriptFile = "../resources/scripts/main";
#ifdef DEBUG
    std::string TrefusisConfig::prefix = "../";
#endif

bool TrefusisConfig::isInitialised = false;

bool TrefusisConfig::initConfig(std::string fileName) {
    if (isInitialised) {
        return true;
    } else {
        FILE* fileptr;
        fileptr = fopen(fileName.c_str(), "r");
        if (fileptr == nullptr) {
            return false; // In  case file is not found etc.
        }
        configFile = fileName;
        std::string token;
        int read_char = 14;
        bool isWriteMode = false;
        std::string writeTo;
        while (read_char != EOF) {
            read_char = fgetc(fileptr);
            switch (read_char) {
                case ' ':
                    isWriteMode = !isWriteMode;
                    writeTo = token;
                    token = "";
                    break;
                case '\n':
                    if (writeTo == "resources") {
                        resourcesDirectory = token;
                    } else if (writeTo == "tilemap") {
                        tilemapLocation = token;
                    } else if (writeTo == "map") {
                        mapFileNames.push_back(token + ".csv");
                    }
                    token = "";
                    break;
                default:
                    token += (char) read_char;
            }
        }
        fclose(fileptr);
        mapsDirectory = resourcesDirectory + "maps/";
        musicsDirectory = resourcesDirectory + "musics/";
        return true;
    }
}