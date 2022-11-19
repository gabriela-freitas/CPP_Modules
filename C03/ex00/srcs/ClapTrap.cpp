
#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& param)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = param.get_name();
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& param)
{
	*this = param;
}

std::string ClapTrap::get_name(void) const
{
	return (this->_name);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap" << " destroyed" << std::endl;
	// TODO (destructor)
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left to attack" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " took damage of " << amount << " points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points--;
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself with " << amount << " hit_points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left to be repaired" << std::endl;
}
