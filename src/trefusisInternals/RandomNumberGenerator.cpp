//
// Created by elsa on 16.04.2020.
//

#include <ctime>
#include <cstdlib>
#include "RandomNumberGenerator.h"

RandomNumberGenerator* RandomNumberGenerator::rng = nullptr;

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