
#include "Form.hpp"
Form::Form() {
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
std::ostream& operator<<(std::ostream& s, const Form& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
