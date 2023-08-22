
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45),
	_target("Default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << _target + " " +this->getName() + " Created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& param):
	AForm("RobotomyRequestForm", 72, 45),
	_target(param.getTarget())
{
	std::cout << _target + " " +this->getName() + " Created as copy" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm" << " destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& param) {
	if (this != &param)
		this->_target = param.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const RobotomyRequestForm& param) {
	std::cout << param.getName() + + " " + param.getTarget() + ", ";
	if (param.getIsSigned())
		std::cout << "is signed";
	else
		std::cout << "is not signed";
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign() << std::endl;
	return (s);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed
// You have to check that the form is signed and that the grade of the
// bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);
	static bool counter = true;

	std::cout << "Making some drilling noises ......." << std::endl;
	if (counter)
		std::cout << _target + " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed: " + _target << std::endl;
	counter = !counter;
}
