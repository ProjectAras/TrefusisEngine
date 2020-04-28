//
// Created by elsa on 15.04.2020.
//

#include <vector>
#include "TrefusisConfig.h"

// DECLARATIONS

std::string TrefusisConfig::configFile;
std::string TrefusisConfig::scriptFile;
std::string TrefusisConfig::levelsLocation;
std::string TrefusisConfig::resourcesDirectory;
std::string TrefusisConfig::mapsDirectory;
std::string TrefusisConfig::musicsDirectory;
std::string TrefusisConfig::splash;
std::string TrefusisConfig::engineSplash;
std::string TrefusisConfig::spritesheet;


#ifdef DEBUG
    std::string TrefusisConfig::prefix = "../";
#else
    std::string TrefusisConfig::prefix;
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
                    } else if (writeTo == "envSpriteSheet") {
                        spritesheet = token;
                    } else if (writeTo == "gameSplashScreen") {
                        splash = token;
                    } else if (writeTo == "splashScreen") {
                        engineSplash = token;
                    } else if (writeTo == "levels") {
                        levelsLocation = token;
                    } else if (writeTo == "script") {
                        scriptFile = token;
                    } else if (writeTo == "maps") {
                        mapsDirectory = token;
                    }
                    token = "";
                    break;
                default:
                    token += (char) read_char;
            }
        }
        fclose(fileptr);
        return true;
    }
}