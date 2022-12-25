#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <gmock/gmock.h>
#include "WordWrap.hpp"

std::string WordWrap::wrapper(const std::string &str, unsigned int width)
{
    std::string remain_line;

	remain_line = str;
	int space = remain_line.find_last_of(" ", width);
	int	split_len;
	int	offset;

    if (remain_line.size() <= width)
	{
		_result << remain_line;
		return _result.str();
	}

	if ((space >= 0) && (space <= (int)width))
	{
		split_len = space;
		offset = 1;
	}
    else 
	{
		split_len = width;
		offset = 0;
	}
	_result << remain_line.substr(0, split_len) << std::endl;
	return wrapper(remain_line.substr(split_len+offset), width);

}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}