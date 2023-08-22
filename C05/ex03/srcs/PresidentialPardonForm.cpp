
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 145, 137),
	_target("Default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 145, 137),
	_target(target)
{
	std::cout << _target + " " +this->getName() + " Created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& param):
	AForm("PresidentialPardonForm", 145, 137),
	_target(param.getTarget())
{
	std::cout << _target + " " +this->getName() + " Created as copy" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm" << " destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& param) {
	if (this != &param)
		this->_target = param.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const PresidentialPardonForm& param) {
	std::cout << param.getName() + + " " + param.getTarget() + ", ";
	if (param.getIsSigned())
		std::cout << "is signed";
	else
		std::cout << "is not signed";
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign() << std::endl;
	return (s);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}


// Informs that <target> has been pardoned by Zaphod Beeblebrox.
// You have to check that the form is signed and that the grade of the
// bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
