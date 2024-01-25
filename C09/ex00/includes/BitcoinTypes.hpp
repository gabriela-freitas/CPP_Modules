#pragma once

#include <ctime>
#include <string>
#include "InvalidInputExeception.hpp"

enum fileType
{
	DATA,
	INPUT
};

struct BitcoinInfo
{
	std::time_t getDate();
	int year;
	int month;
	int day;
	float value;
	void validate(std::string debug, fileType type);
};
