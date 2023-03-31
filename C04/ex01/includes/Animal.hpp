
#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
#include <iostream>
#include "Brain.hpp"

class Animal {
	protected:
		std::string type;

	private:
		Brain *brain;

	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		Animal&	operator= (const Animal&);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
