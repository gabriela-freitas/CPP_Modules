
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__
#include <iostream>
class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter&	operator= (const ScalarConverter&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const ScalarConverter&);
#endif
