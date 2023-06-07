
#include "Form.hpp"

/*TODO: The grades of the Form follow the same rules that apply to the 
Bureaucrat. Thus, the following exceptions will be thrown if a 
form grade is out of bounds: Form::GradeTooHighException and 
Form::GradeTooLowException.*/

Form::Form():
	_name("Default"),
	_gradeExecute(150),
	_gradeSign(150) 
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string _name, const int _gradeExecute, const int _gradeSign) {
	// TODO (default constructor)
}

Form::Form(const Form& param) {
	// TODO (copy constructor)
	(void)param;
}
Form::~Form() {
	std::cout << "Form" << " destroyed" << std::endl;
	// TODO (destructor)
}
Form& Form::operator= (const Form& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
// TODO: write getters for all attributes and an overload of the 
//insertion («) operator that prints all the form’s informations.
std::ostream& operator<<(std::ostream& s, const Form& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}


//TODO:Add also a beSigned() member function to the Form that takes a Bureaucrat as parameter. 
//It changes the form status to signed if the bureaucrat’s grade is high enough 
//(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
//If the grade is too low, throw a Form::GradeTooLowException.

//TODO:add a signForm() member function to the Bureaucrat. If the form got signed, it will print something like:
//   <bureaucrat> signed <form>
//Otherwise, it will print something like:
//<bureaucrat> couldn’t sign <form> because <reason>.