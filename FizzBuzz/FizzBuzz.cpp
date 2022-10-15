#include <string>
#include <vector>
#include <map>
#include <gmock/gmock.h>
#include "FizzBuzz.hpp"


int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
