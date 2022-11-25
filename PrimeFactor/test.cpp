#include <vector>
#include <gmock/gmock.h>
#include "PrimeFactor.hpp"

class PrimeFactorsTest: public ::testing::Test
{
public:
    PrimeFactors prime_factors;
private:
};

TEST_F(PrimeFactorsTest, test_1)
{
	ASSERT_EQ(std::vector<int>{}, prime_factors.generate(1));
}

TEST_F(PrimeFactorsTest, test_2)
{
	ASSERT_EQ(std::vector<int>{2}, prime_factors.generate(2));
}

TEST_F(PrimeFactorsTest, test_3)
{
	ASSERT_EQ(std::vector<int>{3}, prime_factors.generate(3));
}

TEST_F(PrimeFactorsTest, test_4)
{
	ASSERT_EQ(std::vector<int>({2, 2}) , prime_factors.generate(4));
}

TEST_F(PrimeFactorsTest, test_6)
{
	ASSERT_EQ(std::vector<int>({2, 3}) , prime_factors.generate(6));
}

TEST_F(PrimeFactorsTest, test_8)
{
	ASSERT_EQ(std::vector<int>({2, 2, 2}) , prime_factors.generate(8));
}

TEST_F(PrimeFactorsTest, test_9)
{
	ASSERT_EQ(std::vector<int>({3, 3}) , prime_factors.generate(9));
}

TEST_F(PrimeFactorsTest, test_30)
{
	ASSERT_EQ(std::vector<int>({2, 3, 5}) , prime_factors.generate(30));
}