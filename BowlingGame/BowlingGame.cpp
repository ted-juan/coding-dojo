#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "BowlingGame.hpp"

int BowlingGame::score()
{
	int score = 0;
	auto pos =  roll_score.begin();

	for (int i=0; i<frames; i++)
	{	
		score += score_per_frame(pos);
		move_to_next_frame(pos);
	}

	return score;
}

int BowlingGame::score_per_frame(std::vector<int>::iterator &pos)
{
	if (is_strike(pos))
	{
		return strike_score(pos);
	}			
	else if (is_spare(pos))
	{
		return spare_score(pos);
	}			
	else
	{
		return open_frame_score(pos);
	}
}		

void BowlingGame::move_to_next_frame(std::vector<int>::iterator &pos)
{
	if (is_strike(pos))
	{
		pos += 1;
	}			
	else
	{
		pos += 2;
	}			
}		

int BowlingGame::spare_score(const std::vector<int>::iterator pos)
{
	return 10 + *(pos+2);
}		

int BowlingGame::strike_score(const std::vector<int>::iterator pos)
{
	return 10 + *(pos+1) + *(pos+2);
}		

int BowlingGame::open_frame_score(const std::vector<int>::iterator pos)
{
	return *pos + *(pos+1);
}		

bool BowlingGame::is_strike(const std::vector<int>::iterator pos)
{
	return *pos == 10; 
}

bool BowlingGame::is_spare(const std::vector<int>::iterator pos)
{
	return ((*pos + *(pos+1)) == 10);
}

void BowlingGame::roll(int pin)
{
	roll_score.push_back(pin);
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
