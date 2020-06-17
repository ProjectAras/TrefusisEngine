//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_TIMEMANAGER_H
#define TREFUSISENGINE_TIMEMANAGER_H

#include <math.h>
#include "../trefusisInternals/TrefusisConfig.h"

class TimeManager {
private:
    static int tick;
    static constexpr double periodConstant = 3.1415 / (2 * TrefusisConfig::dayLength); // 2*pi/4dt
public:
    static int timeConstant; //WD, WN, SD, SN, SD, SN, AD, AN
    static double globalBrightness; // Determines the brightness level.
    /**
     * Controls the day night cycle.
     */
    static inline void setGlobalBrightness();
    /**
     * Pass the time by ticking it.
     */
    static void tickTime();
    /**
     * Return if it is day right now.
     * @return True if it is day.
     */
    static bool isDay();
    /**
     * Increment seasons.
     */
    static void incrementSeason();
    /**
     * Transition day night.
     */
    static void transitionDayNight();
};


#endif //TREFUSISENGINE_TIMEMANAGER_H
