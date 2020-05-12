//
// Created by elsa on 16.04.2020.
//

#include <ctime>
#include <cstdlib>
#include "RandomNumberGenerator.h"

RandomNumberGenerator* RandomNumberGenerator::rng = nullptr;

float dotProduct(GradientVector* vec1, GradientVector* vec2) {
    return vec1->x*vec2->x + vec1->y*vec2->y;
}

RandomNumberGenerator::RandomNumberGenerator() {
    srand(time(nullptr));
}

double RandomNumberGenerator::random() {
    if (rng == nullptr) {
        rng = new RandomNumberGenerator();
    }
    double result = (double) rand() / (double) RAND_MAX;
    return result;
}

int RandomNumberGenerator::randint(int small, int large) {
    return (rand() % (large - small)) + small;
}