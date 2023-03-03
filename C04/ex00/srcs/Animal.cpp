
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& param) {
	// TODO (copy constructor)
	(void)param;
}

Animal::~Animal() {
	std::cout << "Animal" << " destroyed" << std::endl;
	// TODO (destructor)
}

Animal& Animal::operator= (const Animal& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Animal& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
