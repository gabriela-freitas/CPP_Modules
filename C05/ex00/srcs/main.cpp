
#include "ex00.hpp"
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
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
