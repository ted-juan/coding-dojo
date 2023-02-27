class Soundex
{
public:
	Soundex(){}; 
	~Soundex(){}; 
	std::string encode(const std::string& word);
private:
	const size_t max_encoding_len = 4;
	std::string zero_pad(const std::string& word);
	std::string head(const std::string& word);
	std::string tail(const std::string& word);
	void encode_head (std::string& encoding, const std::string& word);
	void encode_tail (std::string& encoding, const std::string& word);
	void encode_letter (std::string& encoding, char letter, char last_letter);
	bool is_vowel (char letter);
	std::string encode_digits(const std::string& word);
	std::string last_encoding(const std::string& word);
	std::string upper_front(const std::string& word);
	bool is_complete(const std::string& word);
};
