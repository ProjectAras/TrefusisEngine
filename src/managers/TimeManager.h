//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_TIMEMANAGER_H
#define TREFUSISENGINE_TIMEMANAGER_H

class TimeManager {
private:
    static int tick;
public:
    static int timeConstant; //WD, WN, SD, SN, SD, SN, AD, AN
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
