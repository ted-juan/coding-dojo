#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <gmock/gmock.h>
#include "Soundex.hpp"

#if 0
std::map <char, std::string> encoding_map {
	{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
	{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
				{'s', "2"}, {'x', "2"}, {'z', "2"},
	{'d', "3"}, {'t', "3"},
	{'l', "4"},
	{'m', "5"}, {'n', "5"},
	{'r', "6"}
};
#endif

std::string Soundex::encode(const std::string& word)
{
	return "";
}


int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}