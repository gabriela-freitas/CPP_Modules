
#ifndef __CAT_HPP__
# define __CAT_HPP__
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat&);
		~Cat();
		Cat&	operator= (const Cat&);
		void	makeSound(void) const;
		void	think (std::string idea){
			this->brain->think(idea);
		};
		void	readMyMind(void){
			this->brain->readMyMind();
		};
};

#endif
