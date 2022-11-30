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

TEST(word_wrap, wrap_empty_string)
{
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

TEST_F(WordWrapTest, split_one_word_many_times)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", ww.wrapper("wordword", 2));
}

TEST_F(WordWrapTest, split_at_boundary)
{
	ASSERT_EQ("word\nword", ww.wrapper("word word", 5));
}

TEST_F(WordWrapTest, split_one_word_after_boundary)
{
	ASSERT_EQ("word\nword", ww.wrapper("word word", 6));
}

TEST_F(WordWrapTest, split_one_word_before_boundary)
{
	ASSERT_EQ("wor\nd\nwor\nd", ww.wrapper("word word", 3));
}

TEST_F(WordWrapTest, split_one_word_just_before_boundary)
{
	ASSERT_EQ("word\nword", ww.wrapper("word word", 4));
}

TEST_F(WordWrapTest, split_two_word_many_times)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", ww.wrapper("word word", 2));
}
