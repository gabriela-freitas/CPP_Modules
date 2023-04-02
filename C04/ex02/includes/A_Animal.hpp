
#ifndef __A_ANIMAL_HPP__
# define __A_ANIMAL_HPP__
#include <iostream>
#include "Brain.hpp"

class A_Animal {
	protected:
		std::string type;

	public:
		A_Animal();
		A_Animal(const A_Animal&);
		virtual ~A_Animal();
		A_Animal&	operator= (const A_Animal&);
		std::string getType(void) const;
		virtual void makeSound(void) = 0;
};

#endif
