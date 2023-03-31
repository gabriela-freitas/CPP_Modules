
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain&	operator= (const Brain&); // const for safety... not super nesessary
};
#endif
