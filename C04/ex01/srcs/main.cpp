
#include "ex01.hpp"
#define N 4

int	main(void)
{
	{
		Animal *creche_dos_bichinhos[N];

		for (int i = 0; i < N; i++)
		{
			if (i < N / 2)
				creche_dos_bichinhos[i] = new Dog();
			else
				creche_dos_bichinhos[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < N; i++)
			delete creche_dos_bichinhos[i];
	}

	/**TO TEST IF IT'S A DEEP COPY*/
	// std::cout << std::endl;
	// Cat a;

	// a.think("First idea");
	// Cat b(a);
	// b.think("That should be my second idea");
	// b.readMyMind();

	// std::cout << std::endl;
}
