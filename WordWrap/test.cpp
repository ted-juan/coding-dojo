#include <vector>
#include <gmock/gmock.h>
#include "WordWrap.hpp"

/* another solution
https://stackoverflow.com/questions/5815227/fix-improve-word-wrap-function
*/

class WordWrapTest: public ::testing::Test
{
public:
    WordWrap ww;
private:
};

TEST(word_wrap, test_null)
{
    WordWrap ww;

	ASSERT_EQ("", ww.wrapper("", 1));
}

TEST_F(WordWrapTest, string_shorter_than_col)
{
	ASSERT_EQ("this", ww.wrapper("this", 10));
}

TEST_F(WordWrapTest, split_one_word)
{
	ASSERT_EQ("wo\nrd", ww.wrapper("word", 2));
}

TEST_F(WordWrapTest, split_long_word)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", ww.wrapper("wordword", 2));
}

TEST_F(WordWrapTest, split_two_word_with_space)
{
	ASSERT_EQ("word\nword", ww.wrapper("word word", 4));
}

TEST_F(WordWrapTest, split_two_word_and_two_part_with_space)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", ww.wrapper("word word", 2));
}

TEST_F(WordWrapTest, split_two_word_and_mixed_space)
{
	ASSERT_EQ("wor\nd\nwor\nd", ww.wrapper("word word", 3));
}

TEST_F(WordWrapTest, split_two_word_mixed_space2)
{
	ASSERT_EQ("word\nword", ww.wrapper("word word", 6));
}

TEST_F(WordWrapTest, split_two_word_mixed_space3)
{
	ASSERT_EQ("word word", ww.wrapper("word word", 9));
}