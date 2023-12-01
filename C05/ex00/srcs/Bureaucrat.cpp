
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
	_name("Default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	if (this->_grade > 150)
		throw(GradeTooLowException());
	if (this->_grade < 1)
		throw(GradeTooHighException());
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat" << " destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& param) {
	if (this == &param)
		return (*this);
	this->_grade = param.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& param):
	_name(param.getName())
{
	*this = param;
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& param) {
	std::cout << param.getName() + ", bureaucrat grade " << param.getGrade() << std::endl;
	return (s);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}
