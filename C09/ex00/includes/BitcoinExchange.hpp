
#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__
#include <iostream>
#include <map>
#include <ctime>
#include "InvalidInputExeception.hpp"

class BitcoinExchange {
	typedef std::map<std::time_t, float> fileData;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();
		BitcoinExchange&	operator= (const BitcoinExchange&);
	private:
		int parseFile(std::string filename, char delimeter);
		std::map<std::time_t, float> bitcoinPrice;
		std::multimap<std::time_t, float> input;

};
std::ostream&	operator<<(std::ostream&, const BitcoinExchange&);
#endif
