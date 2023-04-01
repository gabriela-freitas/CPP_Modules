
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
		int		_n_ideas;
	public:
		Brain();
		Brain(const Brain&);
		~Brain();
		Brain&	operator= (const Brain&); // const for safety... not super nesessary
		void	think (std::string idea);
		void	readMyMind(void);
};
#endif
