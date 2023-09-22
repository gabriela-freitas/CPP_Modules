
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdlib.h>

# define BLACK	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define WHITE	"\033[1;37m"
# define ENDC	"\033[0m"

int	main()
{
	{
		try {
			std::cout << "#########################################################" << std::endl;
			std::cout << BLUE << "Testing to execute a form that's not signed, should throw exception" << ENDC << std::endl;
			Bureaucrat b("João", 120);
			ShrubberyCreationForm s("Boring");
			std::cout << YELLOW << b << s << ENDC;
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << ENDC << '\n';
		}
	}
	{
		try {
			std::cout << "#########################################################" << std::endl;
			std::cout << BLUE << "Testing to execute a form  with a grade too low, should throw exception" << ENDC << std::endl;
			Bureaucrat b("João", 60);
			RobotomyRequestForm s("Boring");
			std::cout << YELLOW << b << s << ENDC;
			std::cout << GREEN;
			s.beSigned(b);
			std::cout << ENDC;
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << ENDC << '\n';
		}
	}
	{
		try {
			std::cout << "#########################################################" << std::endl;
			std::cout << BLUE << "Testing to sign a form with a grade too low, should throw exception" << ENDC << std::endl;
			Bureaucrat b("João", 80);
			RobotomyRequestForm s("Boring");
			std::cout << YELLOW << b << s << ENDC;
			s.beSigned(b);
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << ENDC << '\n';
		}
	}
	{
		try {
			std::cout << "#########################################################" << std::endl;
			std::cout << BLUE << "Testing to sign a form that's already signed, will not throw exception" << ENDC << std::endl;
			Bureaucrat b("João", 60);
			PresidentialPardonForm s("Boring");
			std::cout << YELLOW << b << s << ENDC;
			s.beSigned(b);
			s.beSigned(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << ENDC << '\n';
		}
	}
	{
		try {
			std::cout << "#########################################################" << std::endl;
			std::cout << BLUE << "Testing to sign and execute a form, beautifully. No exceptions" << ENDC << std::endl;
			Bureaucrat b("João", 2);
			PresidentialPardonForm s("ONE");
			RobotomyRequestForm r("TWO");
			ShrubberyCreationForm t("THREE");
			std::cout << YELLOW << b << s << r << t << ENDC;
			s.beSigned(b);
			r.beSigned(b);
			t.beSigned(b);
			std::cout << "*******" << std::endl;
			b.executeForm(s);
			std::cout << "*******" << std::endl;
			b.executeForm(r);
			std::cout << "*******" << std::endl;
			b.executeForm(t);
			std::cout << "*******" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << ENDC << '\n';
		}
	}
	return (0);
}
