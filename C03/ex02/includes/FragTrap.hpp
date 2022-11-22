
#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap&);
		~FragTrap();
		FragTrap&	operator= (const FragTrap&);
		void attack(const std::string& target);
		void highFivesGuys(void);
};
std::ostream&	operator<<(std::ostream&, const FragTrap&);
#endif
