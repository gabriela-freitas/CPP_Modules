#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include "BitcoinExchange.hpp"
#include <ctime>
#include <iomanip>

std::time_t getValidDate(std::string vdate)
{
	int year = 0, month = 0, day = 0;
	float value = 0;

	sscanf(vdate.c_str(), "%d-%d-%d,%f", &year, &month, &day, &value);
	if (year <= 2009 || year > 2024)
		throw InvalidInputExeception("Invalid year, must be between 2009 and 2024: " + vdate);
	if (month < 1 || month > 12)
		throw InvalidInputExeception("Invalid month: " + vdate);
	if (day < 1 || day > 31)
		throw InvalidInputExeception("Invalid day: " + vdate);
	if (value < 1 || value > 1000)
		throw InvalidInputExeception("Invalid value, must be between 1 and 1000: " + vdate);

	std::tm tm;
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	return std::mktime(&tm);
}

int main(void)
{
	try
	{
		std::time_t a, b;
		a = getValidDate("2024-9-12,100");
		b = getValidDate("2023-09-11,90");
		if (a > b)
		std::cout << "OK" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
