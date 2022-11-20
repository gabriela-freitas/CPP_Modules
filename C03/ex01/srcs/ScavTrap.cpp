
#include "ScavTrap.hpp"
ScavTrap::ScavTrap() {
	// TODO (default constructor)
}
ScavTrap::ScavTrap(const ScavTrap& param) {
	// TODO (copy constructor)
	(void)param;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap" << " destroyed" << std::endl;
	// TODO (destructor)
}
ScavTrap& ScavTrap::operator= (const ScavTrap& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const ScavTrap& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
