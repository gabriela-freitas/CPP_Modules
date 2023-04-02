
#include "Cat.hpp"
#include "ex02.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& param) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = param;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat" << " destroyed" << std::endl;
}

Cat& Cat::operator= (const Cat& param) {
	this->brain = new Brain;
	*(this->brain) = *(param.brain);
	this->type = param.type;
	return (*this);
}

void	Cat::makeSound(void){
	std::cout << "Miau Miau!" << std::endl;
}
