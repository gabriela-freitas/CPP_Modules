
#include "ex00.hpp"
int	main(void)
{
	// const Animal* j = new Dog();
	// const WrongAnimal* i = new WrongCat();
	const Animal* meta = new Cat();
	WrongCat i;
	const WrongAnimal *j = new WrongCat();
	std::cout << BLUE << j->getType() << " " << std::endl;
	std::cout << i.getType() << " " << ENDC << std::endl;
	std::cout << GREEN;
	i.makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << ENDC;


	delete meta;
	// delete i;
	delete j;
	return (0);
}
