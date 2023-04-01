
#include "Dog.hpp"
#include "ex01.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog default constructor called" <<std::endl;
}

Dog::Dog(const Dog& param) {
	this->brain = new Brain;
	std::cout << "Dog copy constructor called" <<std::endl;
	*this = param;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog" << " destroyed" << std::endl;
}

Dog& Dog::operator= (const Dog& param) {
	// if (this->brain)
	// 	delete this->brain;
	*(this->brain) = *(param.brain);
	this->type = param.type;
	return (*this);
}


void	Dog::makeSound(void) const
{
	std::cout << "Au au!" << std::endl;
}

