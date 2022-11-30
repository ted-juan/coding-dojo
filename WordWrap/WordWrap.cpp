#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "WordWrap.hpp"


std::string WordWrap::break_line(std::string s, unsigned int len, unsigned int gap)
{
	result = s.substr(0, len) + "\n" + wrap(s.substr(len + gap));
	return result;
}

std::string WordWrap::wrap(std::string s)
{

	if (s.length() <= _column)
		return s;		

	int space = s.substr(0, _column).find_last_of(" ");

	if (space != -1) 
		return break_line(s, space, 1);
	else if (s.at(_column) == ' ') 
		return break_line(s, _column, 1);
	else		
		return break_line(s, _column, 0);

}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}