
#ifndef __CAT_HPP__
# define __CAT_HPP__
#include <iostream>
class Cat {
	public:
		Cat();
		Cat(const Cat&);
		~Cat();
		Cat&	operator= (const Cat&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const Cat&);
#endif
