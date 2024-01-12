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
	if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("inff"))
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
	return INT;
}


void print(char c)
{
	std::cout << "char: ";
	if (in_limits<char>(c) && !std::isnan(c))
		std::cout << (std::isprint(c) ? ("'" + std::string(1, c) + "'") : "Non printable") << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void print(int num)
{
	std::cout << "int: ";
	if (in_limits<int>(num)&& !std::isnan(num))
		std::cout << num << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void print(float num)
{
	std::cout << "float: " << std::fixed << std::setprecision(3) << num << "f" << std::endl;
}

void print(double num)
{
	std::cout << "double: " << std::fixed << std::setprecision(3) << num << std::endl;
}


void printNumber(int num)
{
	print(static_cast<char>(num));
	print(num);
	print(static_cast<float>(num));
	print(static_cast<double>(num));
}

void printNumber(char num)
{
	print(num);
	print(static_cast<int>(num));
	print(static_cast<float>(num));
	print(static_cast<double>(num));
}

void printNumber(float num)
{
	print(static_cast<char>(num));
	print(static_cast<int>(num));
	print(num);
	print(static_cast<double>(num));
}

void printNumber(double num)
{
	print(static_cast<char>(num));
	print(static_cast<int>(num));
	print(static_cast<float>(num));
	print(num);
}

//TODO: IM NOT DEALING WITH THE IMPOSSIBLE CONVERSIONS (TRY WITH NUMBERS ABOVE INT AND CHAR LIMIT)

void ScalarConverter::converter(std::string literal)
{
	identifyType(literal);
	std::stringstream type;
	std::stringstream conversion;

	type << "Type is: ";
	conversion << literal;
	switch (identifyType(literal))
	{
		case INT:
			type << "int";
			int num;
			conversion >> num;
			printNumber(num);
			break;
		case FLOAT:
			printNumber(strtof(literal.c_str(), NULL));
			type << "float";
			break;
		case CHAR:
			printNumber(literal[0]);
			type << "CHAR";
			break;
		case INVALID:
			type << "INVALID";
			break;
		case DOUBLE:
			printNumber(atof(literal.c_str()));
			type << "DOUBLE";
			break;
		default:
			break;
	}
	std::cout << type.str() << std::endl;
}
