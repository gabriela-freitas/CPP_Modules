
#include "Span.hpp"
Span::Span() {
	// TODO (default constructor)
}
Span::Span(const Span& param) {
	// TODO (copy constructor)
	(void)param;
}
Span::~Span() {
	std::cout << "Span" << " destroyed" << std::endl;
	// TODO (destructor)
}
Span& Span::operator= (const Span& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const Span& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
