
#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
	// TODO (default constructor)
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &param)
{
	// TODO (copy constructor)
	(void)param;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange"
			  << " destroyed" << std::endl;
	// TODO (destructor)
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &param)
{
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream &operator<<(std::ostream &s, const BitcoinExchange &param)
{
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

int parseFile(std::string filename, char delimeter);
