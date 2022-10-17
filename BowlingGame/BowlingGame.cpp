#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "BowlingGame.hpp"

void BowlingGame::roll(int pin)
{
	pins_per_roll.push_back(pin);
}

bool BowlingGame::is_spare(std::vector<int>::iterator &roll_index)
{
	if (*(roll_index) + *(roll_index+1) == 10)
		return true;

	return false;		
}

bool BowlingGame::is_strike(std::vector<int>::iterator &roll_index)
{
	if (*(roll_index) == 10)
		return true;

	return false;		
}

int BowlingGame::open_frame_score(std::vector<int>::iterator &roll_index)
{
	return *(roll_index) + *(roll_index+1);
}

int BowlingGame::strike_bonus(std::vector<int>::iterator &roll_index)
{
	return *(roll_index+1) + *(roll_index+2);
}			

int BowlingGame::spare_bonus(std::vector<int>::iterator &roll_index)
{
	return *(roll_index+2);
}			

int BowlingGame::score()
{
	int score = 0;
	auto roll_index =  pins_per_roll.begin();

	for (int frame=0; frame<10; frame++)
	{
		if (is_strike(roll_index))
		{
			score += 10 + strike_bonus(roll_index);
			roll_index ++;			
		}			
		else if (is_spare(roll_index))
		{
			score += 10 + spare_bonus(roll_index);
			roll_index += 2;			
		}			
		else
		{
			score += open_frame_score(roll_index);
			roll_index += 2;			
		}
	}

	return score;
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
