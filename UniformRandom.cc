#include "UniformRandom.h"

uint32_t UniformRandom::drawNumber(uint32_t min, uint32_t max) {
	return std::uniform_int_distribution<uint32_t>{min,max}(eng);
}
