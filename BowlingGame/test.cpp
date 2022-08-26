#include <vector>
#include <gmock/gmock.h>
#include "BowlingGame.hpp"

class BowlingGameTest: public ::testing::Test
{
public:
	void roll_strike();
	void roll_spare(int pin1, int pin2);
	void roll_many(int frame, int pin);
    BowlingGame game;
private:
};

void BowlingGameTest::roll_many(int times, int pin)
{
	for (int i=0; i<times; i++)
		game.roll(pin);
}

void BowlingGameTest::roll_strike()
{
	game.roll(10);
}

void BowlingGameTest::roll_spare(int pin1, int pin2)
{
	game.roll(pin1);
	game.roll(pin2);
}

TEST(bowling_game_test, test_zero_score)
{
    BowlingGame game;

	for (int i=0; i<20; i++)
		game.roll(0);

	ASSERT_EQ(0, game.score());
}

TEST_F(BowlingGameTest, test_zero_score)
{
	for (int i=0; i<20; i++)
		game.roll(0);

	ASSERT_EQ(0, game.score());
}

TEST_F(BowlingGameTest, roll_many_test)
{
	roll_many(20, 1);
	ASSERT_EQ(20, game.score());
}

TEST_F(BowlingGameTest, roll_spare)
{
	roll_spare(4, 6);
	roll_many(18, 1);
	ASSERT_EQ(29, game.score());
}

TEST_F(BowlingGameTest, roll_two_spare)
{
	roll_spare(5, 5);
	roll_spare(5, 5);
	roll_many(16, 1);
	ASSERT_EQ(42, game.score());
}

TEST_F(BowlingGameTest, roll_strike)
{
	roll_strike();
	roll_many(18, 1);
	ASSERT_EQ(30, game.score());
}

TEST_F(BowlingGameTest, roll_spare_at_end_frame)
{
	roll_many(18, 1);
	roll_spare(4, 6);
	roll_many(1, 5);
	ASSERT_EQ(33, game.score());
}

TEST_F(BowlingGameTest, roll_strike_at_end_frame)
{
	roll_many(18, 1);
	roll_strike();
	roll_many(2, 5);
	ASSERT_EQ(38, game.score());
}

TEST_F(BowlingGameTest, roll_perfect_game)
{
	roll_many(12, 10);
	ASSERT_EQ(300, game.score());
}