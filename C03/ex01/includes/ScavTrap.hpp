
#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const ScavTrap&);
		~ScavTrap();
		ScavTrap&	operator= (const ScavTrap&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const ScavTrap&);
#endif
