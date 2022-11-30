#include <vector>
#include <gmock/gmock.h>
#include "WordWrap.hpp"

class WordWrapTest: public ::testing::Test
{
public:
    WordWrap ww;
private:
};

TEST_F(WordWrapTest, wrap_empty_string)
{
//	ASSERT_EQ("", ww.wrapper("", 1));
}
