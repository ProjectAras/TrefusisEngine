//
// Created by elsa on 19.04.2020.
//

#include "MusicManager.h"
#include "../trefusisInternals/TrefusisConfig.h"
#include <filesystem>

/**
 * Given a file path check if it is a music file belonging to the given level.
 * @param levelName Name of the level.
 * @param entry file path.
 * @return if the file is a music file of a given level ie: levelName_ZoneIndex_musicName.mp3
 */
bool inline isLevelMusicFile(std::string levelName, std::filesystem::directory_entry entry) {
    return entry.path().string().ends_with(".mp3") && entry.path().string().starts_with(levelName);
}

/**
 * Given the filename of a music file belonging to a level, return the zone which it belongs.
 * @param fileName Name of the file.
 * @return the index of the zone it belongs to.
 */
int inline getZoneNumber(std::string fileName) {
    int dashCount = 0; // Number of _'s encountered.
    int i = 0;
    std::string token = "";
    while (dashCount < 2 && i < fileName.size()) {
        char char_ = fileName[i];
        if (char_ == '_') {
            dashCount++;
        } else if (dashCount == 1) {
            token += char_;
        }
        i++;
    }
    return std::atoi(token.c_str());
}

void inline MusicManager::checkLevelVectorSize(int resizeToFit) {
    if (this->levelMusic.size() < resizeToFit)
        this->levelMusic.resize(resizeToFit + 1);
}

bool MusicManager::importLevel(std::string levelName) {
    for (const auto & entry : std::filesystem::directory_iterator(TrefusisConfig::musicsDirectory)) {
        if (isLevelMusicFile(levelName, entry)) {
            std::string fileName = entry.path().string();
            int zoneIndex = getZoneNumber(fileName);
            this->checkLevelVectorSize(zoneIndex);
            this->levelMusic[zoneIndex].push_back(Music {fileName, false});
        }
    }
}