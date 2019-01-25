#ifndef UniformRandom_h
#define UniformRandom_h

#include <random>

class UniformRandom {
	public:
		UniformRandom() = default;
		UniformRandom(std::mt19937::result_type seed) : eng(seed) {}
		uint32_t drawNumber(uint32_t min, uint32_t max);
	private:
		std::mt19937 eng{std::random_device{}()};

};

#endif
