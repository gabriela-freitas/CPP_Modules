
#include "ex01.hpp"
#define N 4

int	main(void)
{
	// {
	// 	Animal *creche_dos_bichinhos[N];

	// 	for (int i = 0; i < N; i++)
	// 	{
	// 		if (i < 5)
	// 			creche_dos_bichinhos[i] = new Dog();
	// 		else
	// 			creche_dos_bichinhos[i] = new Cat();
	// 	}

	// 	std::cout << std::endl;

	// 	creche_dos_bichinhos[0]->think("This is my first idea");
	// 	creche_dos_bichinhos[0]->think("This is my second idea");
	// 	creche_dos_bichinhos[0]->readMyMind();
	// 	creche_dos_bichinhos[0]->think("This is my third idea");
	// 	creche_dos_bichinhos[0]->readMyMind();

	// 	std::cout << std::endl;

	// 	for (int i = 0; i < N; i++)
	// 		delete creche_dos_bichinhos[i];
	// }

	std::cout << std::endl;
	Dog a;

	a.think("First idea");
	Dog b(a);
	b.think("That should be my second idea");
	b.readMyMind();

	std::cout << std::endl;
}
