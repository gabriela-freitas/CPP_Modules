
#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
#include <iostream>
class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal&);
		~Animal();
		Animal&	operator= (const Animal&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const Animal&);
#endif
