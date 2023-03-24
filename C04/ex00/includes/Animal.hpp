
#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
#include <iostream>
class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		Animal&	operator= (const Animal&);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
