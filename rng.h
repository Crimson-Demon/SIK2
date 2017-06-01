#ifndef SITACKA_RNG_H
#define SITACKA_RNG_H

#include <cstdint> // uint64_t

#define MULTIPLIER 279470273
#define MODULUS 4294967291

class RNG {

public:
    RNG(std::uint64_t seed) : seed(seed) { }
    RNG(const RNG& rng) { seed = rng.seed; lastVal = rng.lastVal; };
    ~RNG() { }

	std::uint64_t rand();
    std::uint64_t getSeed() const;
    std::uint64_t getLastVal() const;

private:
    std::uint64_t seed;
    std::uint64_t lastVal = 0;
};

#endif // SITACKA_RNG_H