
#ifndef __INTERN_HPP__
# define __INTERN_HPP__
#include <iostream>
#include <string.h>

class AForm;
typedef  AForm* (*makeFunction)(std::string);

class Intern {
	private:
		static AForm *makePresidentialPardon(std::string target);
		static AForm *makeRobotomyRequest(std::string target);
		static AForm *makeShrubberyCreation(std::string target);
		std::string forms[3];
		makeFunction formsFunc[3];

	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		Intern&	operator= (const Intern&); // const for safety... not super nesessary
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
