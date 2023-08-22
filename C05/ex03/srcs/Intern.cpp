
#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& param) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern" << " destroyed" << std::endl;
}

Intern& Intern::operator= (const Intern& param) {
	return (*this);
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	//TODO:
}



