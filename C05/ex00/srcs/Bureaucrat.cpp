
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade) 
{
	//exceptions for grade
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& param):
	_name(param.getName()),
	_grade(param.getGrade()) 
{
	//exceptions for grade
	std::cout << "Bureaucrat copy constructor called" << std::endl;
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

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

std::ostream& operator<<(std::ostream& s, const Bureaucrat& param)
{
	std::cout << param.getName() << ", Bureaucrat grade " << param.getGrade() << std::endl;
	return (s);
}

void Bureaucrat::incrementGrade(int amount)
{
	//exceptions for grade
	this->_grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
	//exceptions for grade
	this->_grade += amount;
}