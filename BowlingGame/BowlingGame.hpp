class BowlingGame
{
public:
	BowlingGame(){}; 
	~BowlingGame(){}; 
	int score();
	void roll(int pin);
	bool is_spare(std::vector<int>::iterator &roll_index);
	bool is_strike(std::vector<int>::iterator &roll_index);
	int strike_bonus(std::vector<int>::iterator &roll_index);
	int spare_bonus(std::vector<int>::iterator &roll_index);
	int open_frame_score(std::vector<int>::iterator &roll_index);
private:
	std::vector<int> pins_per_roll;
};
