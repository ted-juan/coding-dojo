#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "PrimeFactor.hpp"

const std::vector<int> PrimeFactors::generate(int value)
{
	for (int candicate=2; value > 1; candicate++)
		for (;value % candicate == 0; value /= candicate)
			factors.push_back(candicate);

	return factors;

}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
