//
// Created by elsa on 19.04.2020.
//

#ifndef TREFUSISENGINE_MUSICMANAGER_H
#define TREFUSISENGINE_MUSICMANAGER_H


#include <vector>
#include <string>

struct Music {
    std::string fileName;
    bool loop;
};

class MusicManager {
private:
    std::vector<Music> musicQueue;  // For the scripting engine.
    std::vector<Music> zoneMusic;  // For ordinary zone files.
    std::vector<std::vector<Music>> levelMusic;  // For ordinary zone files.
    Music playingRightNow;
    /**
     * Resize the level matrix if cannot fit integer amount of items.
     * @param resizeToFit Resize to this integer size.
     */
    inline void checkLevelVectorSize(int resizeToFit);
public:
    /**
     * Add a music to the music queue.
     * @return
     */
    bool addToMusicQueue();
    /**
     * Change the zone, changing the ambient musics.
     * @param zoneName
     * @return
     */
    bool changeZone(std::string zoneName);
    bool importLevel(std::string levelName);
};


#endif //TREFUSISENGINE_MUSICMANAGER_H
