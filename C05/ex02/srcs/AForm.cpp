
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():
	_name("Default"),
	_isSigned(false),
	_gradeSign(150),
	_gradeExecute(150)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute):
	_name(name),
	_isSigned(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute)
{
	if (_gradeExecute < 1 || _gradeSign < 1)
		throw GradeTooHighException();
	if (_gradeExecute > 150 || _gradeSign > 150)
		throw GradeTooLowException();
	std::cout << "AForm " + _name + " created" << std::endl;
}

AForm::AForm(const AForm& param):
	_name(param.getName()),
	_isSigned(param.getIsSigned()),
	_gradeSign(param.getGradeSign()),
	_gradeExecute(param.getGradeExecute())
{
	std::cout << "AForm copy constructor called: " + _name << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm" << " destroyed" << std::endl;
}

AForm& AForm::operator= (const AForm& param) {
	if (this != &param)
		this->_isSigned = param.getIsSigned();
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const AForm& param) {
	std::cout << param.getName() + " AForm, ";
	if (param.getIsSigned())
		std::cout << "is signed";
	else
		std::cout << "is not signed";
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign() << std::endl;
	return (s);
}

int AForm::getGradeSign() const {
	return (_gradeSign);
}

int AForm::getGradeExecute() const {
	return (_gradeExecute);
}

bool AForm::getIsSigned() const {
	return (_isSigned);
}

std::string AForm::getName() const {
	return (_name);
}

// Add also a beSigned() member function to the AForm that takes a Bureaucrat as parameter.
// It changes the AForm status to signed if the bureaucrat’s grade is high enough (higher or egal to the required one).
// Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a AForm::GradeTooLowException.
void AForm::beSigned(Bureaucrat &b)
{
	if (b.signAForm(*this))
		_isSigned = true;
	else if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
}

void	AForm::checkRequirements(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeExecute)
		throw GradeTooLowException();
}
