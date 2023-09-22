
#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter() {
	// TODO (default constructor)
}
ScalarConverter::ScalarConverter(const ScalarConverter& param) {
	// TODO (copy constructor)
	(void)param;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter" << " destroyed" << std::endl;
	// TODO (destructor)
}
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const ScalarConverter& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
