#include "A_Animal.hpp"
#include "ex02.hpp"

A_Animal::A_Animal():
	type("A_Animal")
{
	std::cout << "A_Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& param) {
	*this = param;
}

A_Animal::~A_Animal() {
	std::cout << "A_Animal" << " destroyed" << std::endl;
}

A_Animal& A_Animal::operator= (const A_Animal& param) {
	std::cout << "A_Animal Copy constructor called" << std::endl;
	this->type = param.type;
	return (*this);
}

std::string A_Animal::getType(void) const{
	return (this->type);
}
