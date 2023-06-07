
#include "Bureaucrat.hpp"
#include "ex01.hpp"

Bureaucrat::Bureaucrat():
	_name("Default"),
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	try
	{
		if (this->_grade > 150)
			throw(Bureaucrat::GradeTooLowException());
		if (this->_grade < 1)
			throw(Bureaucrat::GradeTooHighException());

	}
	catch (Bureaucrat::myException &e)
	{
		e.message();
		throw (Bureaucrat::myException());
	}
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& param):
	_name(param.getName()),
	_grade(param.getGrade())
{
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
	try
	{
		this->_grade -= amount;
		if (this->_grade > 150)
			throw(Bureaucrat::GradeTooLowException());
		if (this->_grade < 1)
			throw(Bureaucrat::GradeTooHighException());

	}
	catch (Bureaucrat::myException &e)
	{
		e.message();
		throw (Bureaucrat::myException());
	}
}

void Bureaucrat::decrementGrade(int amount)
{
	try
	{
		this->_grade += amount;
		if (this->_grade > 150)
			throw(Bureaucrat::GradeTooLowException());
		if (this->_grade < 1)
			throw(Bureaucrat::GradeTooHighException());

	}
	catch (Bureaucrat::myException &e)
	{
		e.message();
		throw (Bureaucrat::myException());
	}
}

void Bureaucrat::GradeTooHighException::message() const
{
	std::cout << RED << "This grade is too high, try within the range 1 - 150" << ENDC << std::endl;
}


void Bureaucrat::GradeTooLowException::message() const
{
	std::cout << RED << "This grade is too low, try within the range 1 - 150" << ENDC << std::endl;
}

