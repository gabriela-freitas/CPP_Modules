#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>

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

void ScalarConverter::converter(std::string literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]))
	{
		std::cout << "char: " << literal[0] << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << std::fixed << static_cast<float>(literal[0]) << "f" << std::endl;
		std::cout << "double: " << std::fixed << static_cast<double>(literal[0]) << std::endl;
	}
	else
	{
		double d = atof(literal.c_str());
		char c = static_cast<char>(d);
		std::cout << "char: ";
		if (in_limits<char>(d) && !std::isnan(d))
			std::cout << (std::isprint(c) ? ("'" + std::string(1, c) + "'") : "Non printable") << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "int: ";
		if (in_limits<int>(d)&& !std::isnan(d))
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << std::fixed << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << d << std::endl;
	}
}