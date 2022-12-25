#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <gmock/gmock.h>
#include "WordWrap.hpp"

std::string WordWrap::wrapper(const std::string &str, unsigned int width)
{
    std::stringstream ss;
    std::string remain_line;

	remain_line = str;

    while (remain_line.size() > width)
	{
		int space = remain_line.find_last_of(" ", width);
		int	split_len;
		int	offset;
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
		ss << remain_line.substr(0, split_len) << std::endl;
		remain_line = remain_line.substr(split_len + offset);
	}		
	ss << remain_line;
    return ss.str();
}

int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}