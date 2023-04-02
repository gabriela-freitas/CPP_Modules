
#include "ex02.hpp"
#define N 4

int	main(void)
{
	Dog *dog = new Dog();

	dog->makeSound();

	delete dog;

	/**TO TEST IF IT'S A DEEP COPY*/
	// std::cout << std::endl;
	// Cat a;

	// a.think("First idea");
	// Cat b(a);
	// b.think("That should be my second idea");
	// b.readMyMind();

	// std::cout << std::endl;
}
