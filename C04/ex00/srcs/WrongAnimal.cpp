#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():
	type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& param) {
	// TODO (copy constructor)
	*this = param;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal" << " destroyed" << std::endl;
	// TODO (destructor)
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& param) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->type = param.type;
	return (*this);
}

std::string WrongAnimal::getType(void) const{
	return (this->type);
}

void WrongAnimal::makeSound(void) const{
	std::cout << "*** just regular breathing sounds ***" << std::endl;
}
