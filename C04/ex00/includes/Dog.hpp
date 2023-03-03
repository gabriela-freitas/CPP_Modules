
#ifndef __DOG_HPP__
# define __DOG_HPP__
#include <iostream>
class Dog {
	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		Dog&	operator= (const Dog&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const Dog&);
#endif
