class WordWrap
{
public:
	WordWrap(){}; 
	~WordWrap(){}; 
	std::string wrapper(const std::string &str, unsigned int column);
private:
	std::stringstream _result;
};
