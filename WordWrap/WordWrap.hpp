class WordWrap
{
public:
	WordWrap(){}; 
	~WordWrap(){}; 
	std::string wrapper(std::string s, unsigned int column)
	{
		_column = column;
		return wrap(s);
	}
	std::string break_line(std::string s, unsigned int len, unsigned int gap);
private:
	unsigned int _column = 0;
	std::string wrap(std::string s);
	std::string result;
};
