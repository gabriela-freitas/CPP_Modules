
#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& param) {
	*this = param;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat" << " destroyed" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& param) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = param.type;
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "Miau Miau!" << std::endl;
}
