#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "PrimeFactor.hpp"

std::vector<int> PrimeFactors::generate(int value)
{
	std::vector<int> primes;
#if 1	
	for (int candidate = 2; value > 1; candidate++)
	{
		for (;value % candidate == 0; value /= candidate)
		{
			primes.push_back(candidate);
		}
	}			
#else
	int candidate = 2;

	while (value > 1)
	{
		if (value % candidate == 0)
		{
			primes.push_back(candidate);
			value /= candidate;
			continue;
		}
		candidate++;
	}			
#endif
	return primes;
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
