
#include "Brain.hpp"
Brain::Brain() {
	// TODO (default constructor)
}
Brain::Brain(const Brain& param) {
	// TODO (copy constructor)
	(void)param;
}
Brain::~Brain() {
	std::cout << "Brain" << " destroyed" << std::endl;
	// TODO (destructor)
}
Brain& Brain::operator= (const Brain& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const Brain& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
