
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "InvalidInputExeception.hpp"
#include "testingUtils.hpp"
#include "BitcoinTypes.hpp"

class BitcoinExchange
{
	typedef std::map<std::time_t, float> fileData;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	const fileData &getData() const;
	void calculateExchangeRate(std::string inputFile);

private:
	int parseFile(std::string fileName, fileType type);
	fileData bitcoinPrice;
	void calculateAndDisplayResult(BitcoinInfo data);
	void pushBack(BitcoinInfo info, std::string debug, fileType type);
};

#endif
