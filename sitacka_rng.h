#ifndef SITACKA_RNG_H
#define SITACKA_RNG_H

#include <cstdint>

#define MULTIPLIER 279470273
#define MODULUS 4294967291

class RNG {
	static std::uint64_t seed;
	static std::uint64_t lastVal;
	std::uint64_t rand() {
		std::uint64_t newVal = (lastVal * MULTIPLIER) % MODULUS;
		lastVal = newVal;
		return newVal;
	}
}

#endif // SITACKA_RNG_H