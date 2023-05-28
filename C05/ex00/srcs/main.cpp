
#include "ex00.hpp"
int	main(void)
{
	Bureaucrat b("João", 151);
	Bureaucrat a("Mario", 143);

	std::cout << b << std::endl;
	std::cout << a << std::endl;

	a.incrementGrade(10);
	std::cout << a << std::endl;
}
