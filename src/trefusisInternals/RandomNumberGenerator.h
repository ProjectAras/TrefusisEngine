//
// Created by elsa on 16.04.2020.
//

#ifndef TREFUSISENGINE_RANDOMNUMBERGENERATOR_H
#define TREFUSISENGINE_RANDOMNUMBERGENERATOR_H

#include <vector>

struct GradientVector {
    float x;
    float y;
};

/**
 * Take the dot product of two vectors.
 */
float dotProduct(GradientVector* vec1, GradientVector* vec2);

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
    /**
     * Generate a matrix with Perlin Noise.
     * @return a matrix in term of std::vector's of floats.
     */
    static std::vector<std::vector<float>> generatePerlinNoise();
};


#endif //TREFUSISENGINE_RANDOMNUMBERGENERATOR_H
