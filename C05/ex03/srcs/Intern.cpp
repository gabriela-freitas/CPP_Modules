
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
	forms[0] = "PRESIDENTIAL PARDON";
	forms[1] = "ROBOTOMY REQUEST";
	forms[2] ="SHRUBBERY CREATION";
	formsFunc[0] = &makePresidentialPardon;
	formsFunc[1] = &makeRobotomyRequest;
	formsFunc[2] = &makeShrubberyCreation;
}

Intern::Intern(const Intern& param) {
	(void) param;
	std::cout << "Intern copy constructor called" << std::endl;
	forms[0] = "PRESIDENTIAL PARDON";
	forms[1] = "ROBOTOMY REQUEST";
	forms[2] ="SHRUBBERY CREATION";
	formsFunc[0] = &makePresidentialPardon;
	formsFunc[1] = &makeRobotomyRequest;
	formsFunc[2] = &makeShrubberyCreation;
}

Intern::~Intern() {
	std::cout << "Intern" << " destroyed" << std::endl;
}

Intern& Intern::operator= (const Intern& param) {
	(void) param;
	return (*this);
}

// the makeForm() function. It takes
// two strings. The first one is the name of a form and the second one is the target of the
// form. It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.
// It will print something like:
// Intern creates <form>
// If the form name passed as parameter doesn’t exist, print an explicit error message.
AForm *Intern::makePresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequest(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeShrubberyCreation(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static const char * strUpper(std::string &str)
{
	for (size_t i = 0; i < str.size() ; i++)
		str[i] = toupper(str[i]);
	return (str.c_str());
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (strcmp(forms[i].c_str(), strUpper(formName)) == 0)
		{
			std::cout << "Intern creates " + formName + " Form"<< std::endl;
			return (*formsFunc[i])(target);
		}
	}
	std::cout << "Intern couldn't find form " +  formName << std::endl;
	return (NULL);
}



