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

	int found = s.find(" ");

	if ((found > 0) && (found <= (int)_column))
		return break_line(s, found, 1);
	else		
		return break_line(s, _column, 0);

}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}