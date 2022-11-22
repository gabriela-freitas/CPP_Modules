
#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__
#include <iostream>
#include <string>

//had to change private to protected, so these attributes could be accessible
//by the ScavTrap
class ClapTrap {
	protected:
		std::string	_name;
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap&);
		~ClapTrap();
		std::string get_name(void) const;
		ClapTrap&	operator= (const ClapTrap&);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
