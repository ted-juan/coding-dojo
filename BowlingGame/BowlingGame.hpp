class BowlingGame
{
public:
	BowlingGame(){}; 
	~BowlingGame(){}; 
	int score();
	void roll(int pin);
private:
	bool is_spare(const std::vector<int>::iterator pos);
	bool is_strike(const std::vector<int>::iterator pos);
	int open_frame_score(const std::vector<int>::iterator pos);
	int spare_score(const std::vector<int>::iterator pos);
	int strike_score(const std::vector<int>::iterator pos);
	void move_to_next_frame(std::vector<int>::iterator &pos);
	int score_per_frame(std::vector<int>::iterator &pos);
	const int frames = 10;
	std::vector<int> roll_score;
};
