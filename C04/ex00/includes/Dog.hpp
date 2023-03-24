
#ifndef __DOG_HPP__
# define __DOG_HPP__
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog&	operator= (const Dog&);
		void	makeSound(void) const;
};

#endif
