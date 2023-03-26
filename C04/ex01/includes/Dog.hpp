
#ifndef __DOG_HPP__
# define __DOG_HPP__
#include <iostream>
#include "ex01.hpp"

class Dog: public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog&	operator= (const Dog&);
		void	makeSound(void) const;
};

#endif
