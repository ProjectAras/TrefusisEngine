//
// Created by elsa on 13.04.2020.
//

#include "TimeManager.h"
#include "../trefusisInternals/TrefusisConfig.h"

int TimeManager::tick = 0;
int TimeManager::timeConstant = 0;

void TimeManager::incrementSeason() {
    timeConstant += 2;
    timeConstant %= 8;
}

bool TimeManager::isDay() {
    return ((tick % TrefusisConfig::dayLength) == 0) && (tick % (TrefusisConfig::dayLength * 2) != 0);
}

void TimeManager::transitionDayNight() {
    if (isDay()) {
        timeConstant--;
    } else {
        timeConstant++;
    }
}

void TimeManager::tickTime() {
    tick++;
    if ((tick % TrefusisConfig::dayLength) == 0) {
        transitionDayNight();
    }
    if ((tick % TrefusisConfig::seasonLength) == 0) {
        incrementSeason();
    }
}
