#ifndef UniformRandom_h
#define UniformRandom_h

#include <random>

class UniformRandom {
	public:
		UniformRandom() = default;
		UniformRandom(std::mt19937::result_type seed) : eng(seed) {}
		int drawNumber(int min, int max);
	private:
		std::mt19937 eng{std::random_device{}()};

};

#endif
