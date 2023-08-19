
#include "ex00.hpp"
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

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
