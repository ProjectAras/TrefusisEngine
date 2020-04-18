//
// Created by elsa on 16.04.2020.
//

#ifndef TREFUSISENGINE_RANDOMNUMBERGENERATOR_H
#define TREFUSISENGINE_RANDOMNUMBERGENERATOR_H


class RandomNumberGenerator {
private:
    static RandomNumberGenerator* rng;
    /**
     * Initialise a RandomNumberGenerator instance.
     */
    RandomNumberGenerator();

public:
    /**
     * Generate a random number between 0 and 1.
     * @return the generated random number.
     */
    static double random();
    /**
     * Generate a random integer between two integers.
     * @param small smaller number.
     * @param large larger number.
     * @return A random between smaller and larger number, both inclusive.
     */
    static int randint(int small, int large);
};


#endif //TREFUSISENGINE_RANDOMNUMBERGENERATOR_H
