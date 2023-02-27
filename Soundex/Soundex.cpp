#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <gmock/gmock.h>
#include "Soundex.hpp"

std::map <char, std::string> encoding_map {
	{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
	{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
				{'s', "2"}, {'x', "2"}, {'z', "2"},
	{'d', "3"}, {'t', "3"},
	{'l', "4"},
	{'m', "5"}, {'n', "5"},
	{'r', "6"}
};

std::string Soundex::zero_pad(const std::string& word)
{
	int zero_needed = max_encoding_len - word.length();

	return word + std::string(zero_needed, '0');	
}

std::string Soundex::encode(const std::string& word)
{
	return zero_pad(encode_digits(word));
}

std::string Soundex::upper_front(const std::string& word)
{
	return std::string(1, std::toupper(word.front()));
}

std::string Soundex::head(const std::string& word)
{
	return word.substr(0, 1);
}

std::string Soundex::tail(const std::string& word)
{
	return word.substr(1);
}

bool Soundex::is_complete(const std::string& word)
{
	return word.size() == max_encoding_len;
}

std::string Soundex::last_encoding(const std::string& word)
{
	return std::string(1, word.back());
}

void Soundex::encode_head (std::string& encoding, const std::string& word)
{
	encoding =  upper_front(head(word));
}

bool Soundex::is_vowel (char letter)
{
	return std::string("aeiou").find(letter) != std::string::npos;
}

void Soundex::encode_letter (std::string& encoding, char letter, char last_letter)
{
	letter = std::tolower(letter);
	last_letter = std::tolower(last_letter);

	if ((encoding_map[letter] != last_encoding(encoding)) || is_vowel(last_letter))
		encoding += encoding_map[letter];
}

void Soundex::encode_tail (std::string& encoding, const std::string& word)
{
	for (unsigned int i=1; i<word.length(); i++)
	{
		if (!is_complete(encoding))
			encode_letter(encoding, word[i], word[i-1]);
	}		
}

std::string Soundex::encode_digits (const std::string& word)
{
	std::string encoding;

	encode_head(encoding, word);
	encode_tail(encoding, word);
	return encoding;
}


int main(int argc, char** argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}