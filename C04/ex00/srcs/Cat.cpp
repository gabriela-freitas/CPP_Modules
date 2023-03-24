
#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& param) {
	*this = param;
}

Cat::~Cat() {
	std::cout << "Cat" << " destroyed" << std::endl;
}

Cat& Cat::operator= (const Cat& param) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = param.type;
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}
