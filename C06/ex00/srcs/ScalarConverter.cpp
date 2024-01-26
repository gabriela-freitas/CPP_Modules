#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iomanip>

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& param) {
	(void)param;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter" << " destroyed" << std::endl;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& param) {
	(void)param;
	return (*this);
}

template <typename T>
static bool in_limits(double c)
{
	if (c < std::numeric_limits<T>::min() || c > std::numeric_limits<T>::max())
		return false;
	return true;
}

// get type function
// You have to first detect the type of the literal passed as parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below.
// If a conversion does not make any sense or overflows, display a message to inform
// the user that the type conversion is impossible. Include any header you need in order to
// handle numeric limits and special values

enum e_type
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	INVALID
};

e_type identifyType(std::string literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	if ((std::count(literal.begin(), literal.end(), '-')
			+ std::count(literal.begin(), literal.end(), '+')
			+ std::count(literal.begin() + 1, literal.end(), '+')
			+ std::count(literal.begin() + 1, literal.end(), '-')) > 1)
		return INVALID;
	if (std::count(literal.begin(), literal.end(), '.') > 1
		|| *literal.begin() == '.'
		|| *literal.rbegin() == '.')
		return INVALID;

	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan") || !literal.compare("inf") )
		return DOUBLE;
	if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("inff") || !literal.compare("nanf"))
		return FLOAT;
	if (std::count(literal.begin(), literal.end(), 'f') > 1 || std::count(literal.begin(), literal.end(), '.') > 1)
		return INVALID;

	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
	{
		if (*it == '-' || *it == '+' || *it == '.' || *it == 'f')
			continue;
		if (isalpha(*it))
			return INVALID;
	}

	if (std::count(literal.begin(), literal.end(), '.') == 1
		&& *literal.begin() != '.'
		&& *literal.rbegin() != '.')
	{
		if (std::count(literal.begin(), literal.end(), 'f') == 1 && *literal.rbegin() == 'f')
			return FLOAT;
		else
			return DOUBLE;
	}

	int num;
	std::stringstream ss;
	ss << literal;
	ss >> num;

	ss.str(std::string());
	ss.clear();
	ss << num;
	if (!literal.compare(ss.str()))
		return INT;
	return INVALID;
}

void print(double num)
{
	std::cout << "char: ";
	char c = static_cast<char>(num);
	if (in_limits<char>(num) && !std::isnan(num))
		std::cout << (std::isprint(c) ? ("'" + std::string(1, c) + "'") : "Non printable") << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (in_limits<int>(num)&& !std::isnan(num))
		std::cout << static_cast<int>(num) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::converter(std::string literal)
{
	switch (identifyType(literal))
	{
		case INT:
			std::cout << ">> Type is: INT <<" << std::endl;
			if (!in_limits<int>(atof(literal.c_str())))
				std::cout << "Integer overflow" << std::endl;
			else
				print(atof(literal.c_str()));
			break;
		case FLOAT:
			std::cout << ">> Type is: FLOAT <<" << std::endl;
			print(atof(literal.c_str()));
			break;
		case CHAR:
			std::cout << ">> Type is: CHAR <<" << std::endl;
			print((double)literal[0]);
			break;
		case DOUBLE:
			std::cout << ">> Type is: DOUBLE <<" << std::endl;
			print(strtod(literal.c_str(), NULL));
			break;
		case INVALID:
			std::cout << "INVALID INPUT" << std::endl;
			break;
		default:
			break;
	}
}
