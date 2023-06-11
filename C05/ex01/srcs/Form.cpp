
#include "Form.hpp"

/*DONE: The grades of the Form follow the same rules that apply to the 
Bureaucrat. Thus, the following exceptions will be thrown if a 
form grade is out of bounds: Form::GradeTooHighException and 
Form::GradeTooLowException.*/

void Form::GradeTooHighException::message() const
{
	std::cout << RED << "Form: grade too high" << ENDC << std::endl;
}

void Form::GradeTooLowException::message() const
{
	std::cout << RED << "Form: grade too low" << ENDC << std::endl;
}

Form::Form():
	_name("Default"),
	_gradeExecute(150),
	_gradeSign(150) 
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeExecute, const int gradeSign):
	_name(name),
	_gradeExecute(gradeExecute),
	_gradeSign(gradeSign)  
{
	try
	{
		if (this->_gradeExecute > 150 || this->_gradeSign > 150)
			throw(Form::GradeTooLowException());
		if (this->_gradeExecute < 1 || this->_gradeSign < 1)
			throw(Form::GradeTooHighException());

	}
	catch (Form::myException &e)
	{
		e.message();
		throw (Form::myException());
	}
	std::cout << "Form " << name << " created" << std::endl;
} 

Form::Form(const Form& param):
	_name(param.getName()),
	_gradeExecute(param.getGradeExecute()),
	_gradeSign(param.getGradeSign()),
	_isSigned(param.getIsSigned())
{
	std::cout << "Form copy constructor called" << std::endl;
}
Form::~Form() {
	std::cout << "Form" << " destroyed" << std::endl;
}
Form& Form::operator= (const Form& param) {
	if (this == &param)
		return (*this);
	this->_isSigned = param.getIsSigned();	
}

// DONE: write getters for all attributes and an overload of the 
//insertion («) operator that prints all the form’s informations.
std::ostream& operator<<(std::ostream& s, const Form& param) {
	std::cout << "Form: " << param.getName();
	std::cout << " | Grade to execute: " << param.getGradeExecute();
	std::cout << " | Grade to sign: " << param.getGradeSign();
	if (param.getIsSigned())
		std::cout << "| IS SIGNED! :)" << std::endl;
	else
		std::cout << "| IS NOT SIGNED! :(" << std::endl;
	return (s);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeExecute() const
{
	return (this->_gradeExecute);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}


//TODO:Add also a beSigned() member function to the Form that takes a Bureaucrat as parameter. 
//It changes the form status to signed if the bureaucrat’s grade is high enough 
//(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
//If the grade is too low, throw a Form::GradeTooLowException.

void Form::beSigned(const Bureaucrat &b)
{
	try
	{
		if (b.getGrade() <= this->getGradeSign())
		{
			this->_isSigned = true;
			b.signForm(this);
		}
		else
			throw (Form::GradeTooLowException());
	}
	catch (Form::myException &e)
	{
		b.signForm(this);
		e.message();
	}
}


//TODO:add a signForm() member function to the Bureaucrat. If the form got signed, it will print something like:
//   <bureaucrat> signed <form>
//Otherwise, it will print something like:
//<bureaucrat> couldn’t sign <form> because <reason>.