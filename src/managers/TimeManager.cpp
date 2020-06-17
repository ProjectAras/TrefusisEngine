//
// Created by elsa on 13.04.2020.
//

#include "TimeManager.h"
#include "../trefusisInternals/TrefusisConfig.h"
#include <iostream>
int TimeManager::tick = 0;
int TimeManager::timeConstant = 0;
double TimeManager::globalBrightness = 0;

void TimeManager::setGlobalBrightness() {
    if (isDay()) {
        float dayTick = tick % TrefusisConfig::dayLength;
        globalBrightness = 255 - abs(55 * sin(periodConstant * dayTick));  
    }
    #ifdef DEBUG  
        std::cout << globalBrightness << "\n"; 
    #endif 
}

void TimeManager::incrementSeason() {
    timeConstant += 2;
    timeConstant %= 8;
}

bool TimeManager::isDay() {
    return ((tick % TrefusisConfig::dayLength)) == (tick % (TrefusisConfig::dayLength * 2));
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
    setGlobalBrightness();
    if ((tick % TrefusisConfig::seasonLength) == 0) {
        incrementSeason();
    }
}
