
#include "ex01.hpp"
#define N 4

int	main(void)
{
	Animal *creche_dos_bichinhos[N];

	for (int i = 0; i < N; i++)
	{
		if (i < 5)
			creche_dos_bichinhos[i] = new Dog();
		else
			creche_dos_bichinhos[i] = new Cat();
	}

	creche_dos_bichinhos[0]->getType();

	for (int i = 0; i < N; i++)
		delete creche_dos_bichinhos[i];
}
