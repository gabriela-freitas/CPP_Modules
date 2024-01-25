
#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &param)
{
	*this = param;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange"
			  << " destroyed" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &param)
{
	(void)param;
	return (*this);
}

const BitcoinExchange::fileData &BitcoinExchange::getData() const
{
	return (bitcoinPrice);
}

const BitcoinExchange::InputfileData &BitcoinExchange::getInputData() const
{
	return (input);
}

void BitcoinExchange::registerInfomations(std::string inputFile)
{
	parseFile("data.csv", DATA);
	parseFile(inputFile, INPUT);
}

void BitcoinExchange::calculateExchangeRate(BitcoinInfo data)
{
	fileData::iterator info;
	info = bitcoinPrice.lower_bound(data.getDate());
	if (info->first != data.getDate())
		info--;
	std::cout << data.year << "-" << data.month << "-" << data.day << " => " << info->second << "=>"
			  << info->second * data.value << std::endl;
}

void BitcoinExchange::pushBack(BitcoinInfo info, std::string debug, fileType type)
{
	info.validate(debug, type);
	if (type == INPUT)
	{
		calculateExchangeRate(info);
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
					throw InvalidInputExeception("Invalid input: " + line);

				pushBack(info, line, type);
			}
			catch (const std::exception &e)
			{
				printRed(e.what());
			}
		}
	}
	else
		throw InvalidInputExeception("Could not open file: " + fileName);
	return 1;
}
int parseInputFile(void);
