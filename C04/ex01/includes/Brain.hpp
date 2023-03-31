
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
		void	think (std::string idea){
			static int i = -1;

			this->ideas[++i] = idea;
		};
		void	readMyMind(void)
		{
			for(int i = 0; !this->ideas[i].empty(); i ++)
			{
				std::cout << i << ": ";
				std::cout << this->ideas[i] << std::endl;
			}
		};
};
#endif
