
#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		~WrongCat();
		WrongCat&	operator= (const WrongCat&);
		void	makeSound(void) const;
};

#endif
