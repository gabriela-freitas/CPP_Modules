
#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

// Lastly, add a signAForm() member function to the Bureaucrat. If the AForm got signed, it will print something like:
//    <bureaucrat> signed <AForm>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <AForm> because <reason>.
// Implement and turn in some tests to ensure everything works as expected.
bool Bureaucrat::signAForm(AForm& f)
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
		std::cout << "Form is already signed" << std::endl;
	return (false);
}

// TODO: Lastly, add the executeForm(Form const & form) member function to the Bureau- crat. It must attempt to execute the form. If it’s successful, print something like:
//    <bureaucrat> executed <form>
// If not, print an explicit error message.
// Implement and turn in some tests to ensure everything works as expected.
void Bureaucrat::executeForm(AForm const & form)
{
	if (!form.getIsSigned())
		std::cout << _name + " couldn't execute the form because it's not signed: " + form.getName() << std::endl;
	if (_grade > form.getGradeExecute())
		std::cout << _name + " couldn't execute the form because grade is too low: " + form.getName() << std::endl;;
	form.checkRequirements(*this);
	form.execute(*this);
	std::cout << this->_name + " executed " + form.getName() << std::endl;
}
