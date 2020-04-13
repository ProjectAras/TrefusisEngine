//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_TIMEMANAGER_H
#define TREFUSISENGINE_TIMEMANAGER_H

enum SEASON {WINTER, SPRING, SUMMER, AUTUMN};
enum DAYTIME {DAY=1, NIGHT=-1};
class TimeManager {
private:
    int tick;
    SEASON season;
    DAYTIME time;
public:
    void tickTime();
};


#endif //TREFUSISENGINE_TIMEMANAGER_H
