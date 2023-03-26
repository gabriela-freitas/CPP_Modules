
#include "Brain.hpp"
#include "ex01.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& param) {
	*this = param;
}

Brain::~Brain() {
	std::cout << "Brain" << " destroyed" << std::endl;
}

Brain& Brain::operator= (const Brain& param) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = param.ideas[i];
	return (*this);
}

