#include <vector>
#include <gmock/gmock.h>
#include "FizzBuzz.hpp"

class FizzBuzzTest: public ::testing::Test
{
public:
    FizzBuzz fizzbuzz;
private:
};

#if 0
TEST(fizzbuzz_test, test_one)
{
    FizzBuzz fizzbuzz;

	ASSERT_EQ("1", fizzbuzz.output(1));
}
#endif
