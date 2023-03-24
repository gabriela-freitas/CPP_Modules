#include "Animal.hpp"

Animal::Animal():
	type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& param) {
	// TODO (copy constructor)
	*this = param;
}

Animal::~Animal() {
	std::cout << "Animal" << " destroyed" << std::endl;
	// TODO (destructor)
}

Animal& Animal::operator= (const Animal& param) {
	std::cout << "Animal Copy constructor called" << std::endl;
	this->type = param.type;
	return (*this);
}

std::string Animal::getType(void) const{
	return (this->type);
}

void Animal::makeSound(void) const{
	std::cout << "*** just regular breathing sounds ***" << std::endl;
}
