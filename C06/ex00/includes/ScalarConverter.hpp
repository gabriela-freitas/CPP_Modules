
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator= (const ScalarConverter&);

	public:
		~ScalarConverter();
		static void converter (std::string literal);
};

#endif
