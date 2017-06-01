#include "rng.h"

std::uint64_t RNG::rand() {
    std::uint64_t newVal = (lastVal * MULTIPLIER) % MODULUS;
    lastVal = newVal;
    return newVal;
}

std::uint64_t RNG::getSeed() const {
    return seed;
}

std::uint64_t RNG::getLastVal() const {
    return lastVal;
}