#include <gmock/gmock.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Soundex.hpp"

/*
規則1 : 保留第一個字母，丟掉所有出現的a、e、i、o、u、y、h、w
規則2 : 以數字來代替輔音（第一個字母除外）：

    b f p v -> 1
    c g j k q s x z -> 2
    d t -> 3
    l -> 4
    m n -> 5
    r -> 6

規則3 :
對於相鄰的重複的數字只保留一個，即相鄰的兩個被取代為同一個數字的字母只保留一個；
如果出現兩個編碼相同的字母，且它們被 h 和 w 隔開，也這樣處理；
但如果被母音(a,e,i,o,u)隔開，就要編碼兩次。這條規則同樣適用於第一個字母。

規則4 : 當得到一個字母和三個數字時，停止處理。如果需要，補零以對齊。
(補充) 規則5 : 希望輸出字母是大寫, 輸入時不分大小寫都視為小寫
*/

class SoundexTest : public ::testing::Test {
public:
  Soundex soundex;

private:
};

/*規則4 : 當得到一個字母和三個數字時，停止處理。如果需要，補零以對齊。*/
TEST_F(SoundexTest, RetainFirstLastWordAndPadZero) {
  //ASSERT_EQ("A000", soundex.encode("A"));
}

#if 0
/* // 規則2 : 以數字來代替輔音（第一個字母除外）： */
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

// 規則4 : 當得到一個字母和三個數字時，停止處理。如果需要，補零以對齊。
TEST_F(SoundexTest, LimitFourCharacters) {
  ASSERT_EQ("A234", soundex.encode("Acdlb"));
}

// 規則1 : 保留第一個字母，丟掉所有出現的a、e、i、o、u、y、h、w
TEST_F(SoundexTest, IgnoresVowelLikeLetters) {
  ASSERT_EQ("B234", soundex.encode("Baeiouhywcdl"));
}

// 規則3 : 對於相鄰的重複的數字只保留一個，即相鄰的兩個被取代為同一個數字的字母只保留一個
TEST_F(SoundexTest, CombineDuplicateEncodings) {
  ASSERT_EQ("A123", soundex.encode("Abfcgdt"));
}

TEST_F(SoundexTest, TestFirstLetterLowerCase) {
  ASSERT_EQ("B123", soundex.encode("Bbfcgdt"));
}

// (補充) 規則5 : 希望輸出字母是大寫, 輸入時不分大小寫都視為小寫
TEST_F(SoundexTest, TestTailLetterUpperCase) {
  ASSERT_EQ("B123", soundex.encode("bBFCGDT"));
}

// 規則3 : 但如果被母音(a,e,i,o,u)隔開，就要編碼兩次。這條規則同樣適用於第一個字母。
TEST_F(SoundexTest, DoesNotCombineDuplicateEncodingsSeparateByVowels) {
  ASSERT_EQ("J110", soundex.encode("Jbob"));
}
#endif