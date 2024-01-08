#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

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

//TODO: get type function
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
	int intValue;
	float floatValue;
	std::stringstream ss;

	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	if ((std::count(literal.begin(), literal.end(), '-')
			+ std::count(literal.begin(), literal.end(), '+')) > 1)
		return INVALID;
	if (std::count(literal.begin(), literal.end(), '.') > 1
		|| *literal.begin() == '.'
		|| *literal.end() == '.')
		return INVALID;

	ss << literal;
	ss >> intValue;
	ss >> floatValue;

	if (intValue == 0)
	{
		if (!literal.compare("0"))
			return INT;
		if (!literal.compare("0.0") || !literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
			return DOUBLE;
		if (!literal.compare("0.0F") || !literal.compare("-inff") || !literal.compare("+inff"))
			return FLOAT;
	}
	for (std::string::iterator it = literal.begin(); it != literal.end(); it++)
	{
		if (it != literal.begin() && isalpha(*it))
			return INVALID;
		else if (isalpha(*it) && (*it == '-' || *it == '+' || *it == '.' || *it == 'f'))
			continue;
	}

	//FIXME:
	if (std::count(literal.begin(), literal.end(), 'f') == 1 && *literal.end() == 'f')
		return FLOAT;
	if (std::count(literal.begin(), literal.end(), '.') == 1
		|| *literal.begin() != '.'
		|| *literal.end() != '.')
		return DOUBLE;
	return INT;

}


void ScalarConverter::converter(std::string literal)
{
	std::stringstream conv;

	conv << "Type is: ";
	switch (identifyType(literal))
	{
		case INT:
			conv << "int";
			break;
		case FLOAT:
			conv << "float";
			break;
		case CHAR:
			conv << "CHAR";
			break;
		case INVALID:
			conv << "INVALID";
			break;
		case DOUBLE:
			conv << "DOUBLE";
			break;
		default:
			break;
	}
	std::cout << conv.str() << std::endl;
}


// void ScalarConverter::converter(std::string literal)
// {
// 	if (literal.size() == 1 && !std::isdigit(literal[0]))
// 	{
// 		std::cout << "char: " << literal[0] << std::endl;
// 		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
// 		std::cout << "float: " << std::fixed << static_cast<float>(literal[0]) << "f" << std::endl;
// 		std::cout << "double: " << std::fixed << static_cast<double>(literal[0]) << std::endl;
// 	}
// 	else
// 	{
// 		double d = atof(literal.c_str());
// 		char c = static_cast<char>(d);
// 		std::cout << "char: ";
// 		if (in_limits<char>(d) && !std::isnan(d))
// 			std::cout << (std::isprint(c) ? ("'" + std::string(1, c) + "'") : "Non printable") << std::endl;
// 		else
// 			std::cout << "impossible" << std::endl;

// 		std::cout << "int: ";
// 		if (in_limits<int>(d)&& !std::isnan(d))
// 			std::cout << static_cast<int>(d) << std::endl;
// 		else
// 			std::cout << "impossible" << std::endl;
// 		std::cout << "float: " << std::fixed << static_cast<float>(d) << "f" << std::endl;
// 		std::cout << "double: " << std::fixed << d << std::endl;
// 	}
// }
