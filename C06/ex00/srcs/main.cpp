
#include "ex00.hpp"
#include "ScalarConverter.hpp"

int	main(int ac, char** av)
{
	if (ac > 1)
		ScalarConverter::converter(av[1]);
	return (0);
}
