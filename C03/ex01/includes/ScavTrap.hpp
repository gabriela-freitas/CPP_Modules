
#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&);
		~ScavTrap();
		ScavTrap&	operator= (const ScavTrap&);
		void attack(const std::string& target);
		void guardGate(void);
};
std::ostream&	operator<<(std::ostream&, const ScavTrap&);
#endif
