class PrimeFactors
{
public:
	PrimeFactors(){}; 
	~PrimeFactors(){}; 
	const std::vector<int> generate(int value);
private:
	std::vector<int> factors;
};
