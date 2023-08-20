
#include "Form.hpp"

Form::Form():
	_name("Default"),
	_isSigned(false),
	_gradeSign(150),
	_gradeExecute(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExecute):
	_name(name),
	_isSigned(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute)
{
	if (_gradeExecute < 1 || _gradeSign < 1)
		throw GradeTooHighException();
	if (_gradeExecute > 150 || _gradeSign > 150)
		throw GradeTooLowException();
	std::cout << "Form " + _name + " created" << std::endl;
}

Form::Form(const Form& param):
	_name(param.getName()),
	_isSigned(param.getIsSigned()),
	_gradeSign(param.getGradeSign()),
	_gradeExecute(param.getGradeExecute())
{
	std::cout << "Form copy constructor called: " + _name << std::endl;
}

Form::~Form() {
	std::cout << "Form" << " destroyed" << std::endl;
}

Form& Form::operator= (const Form& param) {
	if (this != &param)
		this->_isSigned = param.getIsSigned();
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const Form& param) {
	std::cout << param.getName() + " Form, ";
	if (param.getIsSigned())
		std::cout << "is signed";
	else
		std::cout << "is not signed";
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign() << std::endl;
	return (s);
}

int Form::getGradeSign() const {
	return (_gradeSign);
}

int Form::getGradeExecute() const {
	return (_gradeExecute);
}

bool Form::getIsSigned() const {
	return (_isSigned);
}

std::string Form::getName() const {
	return (_name);
}

// Add also a beSigned() member function to the Form that takes a Bureaucrat as parameter.
// It changes the form status to signed if the bureaucrat’s grade is high enough (higher or egal to the required one).
// Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.
void Form::beSigned(Bureaucrat &b)
{
	if (b.signForm(*this))
		_isSigned = true;
	else if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
}
