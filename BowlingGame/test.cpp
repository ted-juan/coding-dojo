#include <vector>
#include <gmock/gmock.h>
#include "BowlingGame.hpp"

class BowlingGameTest: public ::testing::Test
{
public:
    BowlingGame game;
    void roll_many(int frame, int pins);
    void roll_spare(int pin1, int pin2);
private:
};

void BowlingGameTest::roll_many(int frame, int pins)
{
    for (int i=0; i<frame; i++)
        game.roll(pins);
}

void BowlingGameTest::roll_spare(int pin1, int pin2)
{
    game.roll(pin1);
    game.roll(pin2);
}

TEST(bowling_game_test, test_all_zero)
{
    BowlingGame game;

    for (int i=0; i<20; i++)
        game.roll(0);

	ASSERT_EQ(0, game.score());
}

TEST_F(BowlingGameTest, test_roll_many)
{
    roll_many(20, 1);

	ASSERT_EQ(20, game.score());
}

TEST_F(BowlingGameTest, test_spare)
{
    roll_many(1, 9);
    roll_many(1, 1);
    roll_many(1, 3);
    roll_many(17, 0);

	ASSERT_EQ(16, game.score());
}

TEST_F(BowlingGameTest, test_one_spare)
{
    roll_spare(1, 9);
    roll_many(1, 3);
    roll_many(17, 0);

	ASSERT_EQ(16, game.score());
}

TEST_F(BowlingGameTest, test_one_strike)
{
    game.roll(10);
    roll_many(1, 3);
    roll_many(1, 4);
    roll_many(16, 0);

	ASSERT_EQ(24, game.score());
}

TEST_F(BowlingGameTest, test_perfect_game)
{
    roll_many(12, 10);

	ASSERT_EQ(300, game.score());
}