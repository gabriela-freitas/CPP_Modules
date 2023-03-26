
#include "ex01.hpp"

int	main(void)
{
	Animal *creche_dos_bichinhos[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			creche_dos_bichinhos[i] = new Dog();
		else
			creche_dos_bichinhos[i] = new Cat();
	}
	delete creche_dos_bichinhos;
}
