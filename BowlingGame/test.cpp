#include <vector>
#include <gmock/gmock.h>
#include "BowlingGame.hpp"

class BowlingGameTest: public ::testing::Test
{
public:
    BowlingGame game;
private:
};

#if 0
TEST(bowling_game_test, test_zero_score)
{
    BowlingGame game;

	ASSERT_EQ(0, game.score());
}
#endif