
#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal();
		WrongAnimal&	operator= (const WrongAnimal&);
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif
