
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
	if (this != &param)
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

void	Bureaucrat::incrementGrade(int grade)
{
	if (_grade - grade < 1)
		throw GradeTooHighException();
	_grade -= grade;
}

void	Bureaucrat::decrementGrade(int grade)
{
	if (_grade + grade < 1)
		throw GradeTooLowException();
	_grade += grade;
}

// Lastly, add a signForm() member function to the Bureaucrat. If the form got signed, it will print something like:
//    <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>.
// Implement and turn in some tests to ensure everything works as expected.
bool Bureaucrat::signForm(Form& f)
{
	if (!f.getIsSigned() && _grade <= f.getGradeSign())
	{
		std::cout << _name + " signed " << f.getName() << std::endl;
		return (true);
	}
	std::cout << _name + " couldn't sign " + f.getName() + " because ";
	if  (_grade > f.getGradeSign())
		std::cout << "grade is too low" << std::endl;
	else if (f.getIsSigned())
		std::cout << "form is already signed" << std::endl;
	return (false);
}
