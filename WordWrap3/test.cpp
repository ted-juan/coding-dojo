#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <gmock/gmock.h>
#include "WordWrap.hpp"

class WordWrapTest: public ::testing::Test
{
public:
    WordWrap word_wrap;
private:
};

TEST_F(WordWrapTest, wrap_empty_string)
{
	ASSERT_EQ("", word_wrap.wrapper("", 1));
}

TEST_F(WordWrapTest, one_char)
{
	ASSERT_EQ("w", word_wrap.wrapper("w", 1));
}

TEST_F(WordWrapTest, one_word_equal_col)
{
	ASSERT_EQ("word", word_wrap.wrapper("word", 4));
}

TEST_F(WordWrapTest, string_shorter_than_col)
{
	ASSERT_EQ("word", word_wrap.wrapper("word", 10));
}

TEST_F(WordWrapTest, split_one_word)
{
	ASSERT_EQ("wo\nrd", word_wrap.wrapper("word", 2));
}

TEST_F(WordWrapTest, split_one_word_many_times)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", word_wrap.wrapper("wordword", 2));
}

TEST_F(WordWrapTest, split_at_boundary)
{
	ASSERT_EQ("word\nword", word_wrap.wrapper("word word", 5));
}

TEST_F(WordWrapTest, split_one_word_after_boundary)
{
	ASSERT_EQ("word\nword", word_wrap.wrapper("word word", 6));
}

TEST_F(WordWrapTest, split_one_word_before_boundary)
{
	ASSERT_EQ("wor\nd\nwor\nd", word_wrap.wrapper("word word", 3));
}

TEST_F(WordWrapTest, split_one_word_just_before_boundary)
{
	ASSERT_EQ("word\nword", word_wrap.wrapper("word word", 4));
}

TEST_F(WordWrapTest, split_two_word_many_times)
{
	ASSERT_EQ("wo\nrd\nwo\nrd", word_wrap.wrapper("word word", 2));
}

TEST_F(WordWrapTest, split_three_word_many_times)
{
	ASSERT_EQ("wo\nrd\nwo\nrd\nwo\nrd", word_wrap.wrapper("word word word", 2));
}

TEST_F(WordWrapTest, split_word_and_skip_space)
{
	ASSERT_EQ("word word\nword", word_wrap.wrapper("word word word", 10));
}

TEST_F(WordWrapTest, split_word_with_starting_space)
{
	ASSERT_EQ(" word word\nword", word_wrap.wrapper(" word word word", 11));
}