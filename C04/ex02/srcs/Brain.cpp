
#include "Brain.hpp"
#include "ex02.hpp"

Brain::Brain():
	_n_ideas(-1) {
	while (this->_n_ideas < 100 && !this->_ideas[this->_n_ideas++].empty())
		;
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& param):
	_n_ideas(-1) {
	while (this->_n_ideas < 100 && !this->_ideas[this->_n_ideas++].empty())
		;
	*this = param;
}

Brain::~Brain() {
	std::cout << "Brain" << " destroyed" << std::endl;
}

Brain& Brain::operator= (const Brain& param) {
	for (int i = 0; i < 100 && !param._ideas[i].empty(); i++)
		this->_ideas[i] = param._ideas[i];
	this->_n_ideas = param._n_ideas;
	return (*this);
}

void	Brain::think (std::string idea){
	this->_ideas[this->_n_ideas++] = idea;
}

void	Brain::readMyMind(void)
{
	for(int i = 0; !this->_ideas[i].empty(); i ++)
	{
		std::cout << i << ": ";
		std::cout << this->_ideas[i] << std::endl;
	}
}

