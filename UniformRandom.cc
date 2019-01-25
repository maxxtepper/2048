#include "UniformRandom.h"

int UniformRandom::drawNumber(int min, int max) {
	return std::uniform_int_distribution<int>{min,max}(eng);
}
