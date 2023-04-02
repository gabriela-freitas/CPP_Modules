
#ifndef __DOG_HPP__
# define __DOG_HPP__
#include <iostream>
#include "ex02.hpp"

class Dog: public A_Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog&	operator= (const Dog&);
		void	makeSound(void);
		void	think (std::string idea){
			this->brain->think(idea);
		};
		void	readMyMind(void){
			this->brain->readMyMind();
		};
};

#endif
