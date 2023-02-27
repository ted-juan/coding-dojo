#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <gmock/gmock.h>
#include "Soundex.hpp"

class SoundexTest: public ::testing::Test
{
public:
    Soundex soundex;

private:
};

TEST_F(SoundexTest, RetainFirstLastWordAndPadZero) {
  ASSERT_EQ("A000", soundex.encode("A"));
}

TEST_F(SoundexTest, RetainFirstLastWordAndReplaceDigital_b) {
  ASSERT_EQ("A100", soundex.encode("Ab"));
}

TEST_F(SoundexTest, RetainFirstLastWordAndReplaceDigital_c) {
  ASSERT_EQ("A200", soundex.encode("Ac"));
}

TEST_F(SoundexTest, IgnoreNonLetter) {
  ASSERT_EQ("A000", soundex.encode("A#"));
}

TEST_F(SoundexTest, ReplaceMultiDigitals) {
  ASSERT_EQ("A234", soundex.encode("Acdl"));
}

TEST_F(SoundexTest, LimitFourCharacters) {
  ASSERT_EQ("A234", soundex.encode("Acdlb"));
}

TEST_F(SoundexTest, IgnoresVowelLikeLetters) {
  ASSERT_EQ("B234", soundex.encode("Baeiouhywcdl"));
}

TEST_F(SoundexTest, CombineDuplicateEncodings) {
  ASSERT_EQ("A123", soundex.encode("Abfcgdt"));
}

TEST_F(SoundexTest, TestFirstLetterLowerCase) {
  ASSERT_EQ("B123", soundex.encode("bbfcgdt"));
}

TEST_F(SoundexTest, TestTailLetterUpperCase) {
  ASSERT_EQ("B123", soundex.encode("BBFCGDT"));
}

TEST_F(SoundexTest, DoesNotCombineDuplicateEncodingsSeparateByVowels) {
  ASSERT_EQ("J110", soundex.encode("Jbob"));
}