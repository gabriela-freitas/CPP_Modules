
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

std::time_t getDate(int year, int month, int day, std::string vdate)
{
	if (year < 2009 || year > 2024)
		throw InvalidInputExeception("Invalid year, must be between 2009 and 2024: " + vdate);
	if (month < 1 || month > 12)
		throw InvalidInputExeception("Invalid month: " + vdate);
	if (day < 1 || day > 31)
		throw InvalidInputExeception("Invalid day: " + vdate);
	std::tm tm;
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;

	return std::mktime(&tm);
}

int parseDataFile(void)
{
	int year = 0, month = 0, day = 0;
	float value = 0;
	// Open the file
	std::ifstream inputFile("data.csv");

	// Check if the file is open
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			try
			{
				// TODO: skip first line
				// TODO: add these values to the container
				if (sscanf(line.c_str(), "%d-%d-%d,%f", &year, &month, &day, &value) != 4)
					throw InvalidInputExeception("Invalid input: " + line);

				// this is only valid on the other file
				//  if (value < 1 || value > 1000)
				//  	throw InvalidInputExeception("Invalid value, must be between 1 and 1000: " + vdate);
				getDate(year, month, day, line);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	throw InvalidInputExeception("Could not open file");
}
int parseInputFile(void);
