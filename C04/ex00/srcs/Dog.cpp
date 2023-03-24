
#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog default constructor called" <<std::endl;
}

Dog::Dog(const Dog& param) {
	*this = param;
}

Dog::~Dog() {
	std::cout << "Dog" << " destroyed" << std::endl;
}

Dog& Dog::operator= (const Dog& param) {
	this->type = param.type;
	return (*this);
}


void	Dog::makeSound(void) const
{
	std::cout << "Au au!" << std::endl;
}

