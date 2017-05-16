#ifndef SITACKA_RNG_H
#define SITACKA_RNG_H

#define MULTIPLIER 279470273
#define MODULUS 4294967291

class RNG {
	static uint64_t seed;
	static uint64_t lastVal;
	uint64_t rand() {
		uint64_t newVal = (lastVal * MULTIPLIER) % MODULUS;
		lastVal = newVal;
		return newVal;
	}
}

#endif // SITACKA_RNG_H