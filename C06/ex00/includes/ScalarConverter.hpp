
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <iostream>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter&	operator= (const ScalarConverter&);
		static void converter (std::string literal);
};

#endif
