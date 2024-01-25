#include "BitcoinTypes.hpp"

std::time_t BitcoinInfo::getDate()
{
	std::tm tm;
	tm.tm_year = this->year - 1900;
	tm.tm_mon = this->month - 1;
	tm.tm_mday = this->day;
	tm.tm_hour = 12;
	tm.tm_min = 30;
	tm.tm_sec = 0;
	return std::mktime(&tm);
}

bool isValidDate(BitcoinInfo &param)
{
	time_t date = param.getDate();
	std::tm *tm = std::localtime(&(date));

	if (tm->tm_year + 1900 == param.year &&
		tm->tm_mon + 1 == param.month &&
		tm->tm_mday == param.day)
		return true;
	return false;
}

void BitcoinInfo::validate(std::string debug, fileType type)
{
	if (!isValidDate(*this))
		throw InvalidInputExeception("Error: invalid date => " + debug);
	if (this->year < 2009 || this->year > 2024)
		throw InvalidInputExeception("Error: Invalid year, must be between 2009 and 2024 =>" + debug);
	if (this->month < 1 || this->month > 12)
		throw InvalidInputExeception("Error: Invalid month =>" + debug);
	if (this->day < 1 || this->day > 31)
		throw InvalidInputExeception("Error: Invalid day =>" + debug);
	if (type == INPUT)
	{
		if (this->value < 1 || this->value > 1000)
			throw InvalidInputExeception("Error: Invalid value, must be between 1 and 1000 =>" + debug);
	}
	else
	{
		if (this->value < 0)
			throw InvalidInputExeception("Error: Invalid value, must be positive =>" + debug);
	}
}