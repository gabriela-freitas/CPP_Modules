
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(int ac, char **av)
{
	Intern bob;

	if (ac > 1)
	{
		std::cout << std::endl;
		bob.makeForm(av[1], "blob");
	}
	std::cout << std::endl;
	bob.makeForm("presidential pardon", "blob");
	std::cout << std::endl;
	bob.makeForm("RoBotoMy ReqUesT", "blob");
	std::cout << std::endl;
	bob.makeForm("SHRUBBERY CREATION", "blob");
	std::cout << std::endl;
	bob.makeForm("whatever", "blob");

	return (0);
}
