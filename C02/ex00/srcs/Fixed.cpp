
#include "Fixed.hpp"
Fixed::Fixed() {
	// TODO (default constructor)
}
Fixed::Fixed(const Fixed& param) {
	// TODO (copy constructor)
	(void)param;
}
Fixed::~Fixed() {
	std::cout << "Fixed" << " destroyed" << std::endl;
	// TODO (destructor)
}
Fixed& Fixed::operator= (const Fixed& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const Fixed& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
