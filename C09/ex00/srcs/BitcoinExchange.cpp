
#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &param){
	(void)param;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &param)
{
	(void)param;
	return (*this);
}

const BitcoinExchange::fileData &BitcoinExchange::getData() const
{
	return (bitcoinPrice);
}

void BitcoinExchange::calculateExchangeRate(std::string inputFile)
{
	parseFile("data.csv", DATA);
	parseFile(inputFile, INPUT);
}

void BitcoinExchange::calculateAndDisplayResult(BitcoinInfo data)
{
	fileData::iterator info;
	info = bitcoinPrice.lower_bound(data.getDate());
	if (abs(info->first - data.getDate()) > 86400)
	{
		info--;
	}
	std::cout << data.year << "-" << data.month << "-" << data.day << " => " << data.value << " => "
			  << info->second * data.value << std::endl;
}

void BitcoinExchange::pushBack(BitcoinInfo info, std::string debug, fileType type)
{
	info.validate(debug, type);
	if (type == INPUT)
	{
		calculateAndDisplayResult(info);
	}
	else
		bitcoinPrice[info.getDate()] = info.value;
}

int BitcoinExchange::parseFile(std::string fileName, fileType type)
{
	BitcoinInfo info;
	std::ifstream inputFile(fileName.c_str());
	std::string tformat;

	if (type == INPUT)
		tformat = "%d-%d-%d | %f";
	else
		tformat = "%d-%d-%d,%f";

	if (inputFile.is_open())
	{
		std::string line;
		for (int i = 1; std::getline(inputFile, line); i++)
		{
			if (i == 1)
				continue;
			try
			{
				if (sscanf(line.c_str(), tformat.c_str(), &info.year, &info.month, &info.day, &info.value) != 4)
					throw InvalidInputExeception("Error: bad input => " + line);

				pushBack(info, line, type);
			}
			catch (const std::exception &e)
			{
				printRed(e.what());
			}
		}
	}
	else
		throw InvalidInputExeception("Error: could not open file: " + fileName);
	return 1;
}
