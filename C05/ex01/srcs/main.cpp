
#include "ex01.hpp"
#include <stdlib.h>

int	main(int ac, char **av)
{
	try
	{
		int grade;
		if (ac > 1)
			grade = atoi(av[1]);
		else
			grade = 120;
		Bureaucrat b("João", grade);
		Form f("Boring", 151, 50);
		std::cout << b << f;
		f.beSigned(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
