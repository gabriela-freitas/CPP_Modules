
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(int ac, char **av)
{
	Intern bob;
	AForm *f;

	if (ac > 1)
	{
		std::cout << std::endl;
		bob.makeForm(av[1], "blob");
	}
	std::cout << std::endl;
	f = bob.makeForm("presidential pardon", "blob");
	delete f;
	std::cout << std::endl;
	f = bob.makeForm("RoBotoMy ReqUesT", "blob");
	delete f;
	std::cout << std::endl;
	f = bob.makeForm("SHRUBBERY CREATION", "blob");
	delete f;
	std::cout << std::endl;
	f = bob.makeForm("whatever", "blob");
	delete f;
	
	return (0);
}
