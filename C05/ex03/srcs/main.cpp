
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		ShrubberyCreationForm s("Boring");
		PresidentialPardonForm p("Boring");
		RobotomyRequestForm r("Boring");

		std::cout << b << s << p << r;

		s.beSigned(b);
		std::cout << std::endl;
		p.beSigned(b);
		std::cout << std::endl;
		r.beSigned(b);
		std::cout << std::endl;
		b.executeForm(s);
		std::cout << std::endl;
		b.executeForm(p);
		std::cout << std::endl;
		b.executeForm(r);
		std::cout << std::endl;
		b.executeForm(r);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
