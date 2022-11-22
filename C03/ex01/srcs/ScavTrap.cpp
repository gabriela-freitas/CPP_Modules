
#include "ScavTrap.hpp"
ScavTrap::ScavTrap()
{
	_hit_points = 100;
	_energy_points = 25;
	_attack_damage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_hit_points = 100;
	_energy_points = 25;
	_attack_damage = 20;
	_name = name;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& param) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->_name = param.get_name();
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& param) {
	*this = param;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap" << " destroyed" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name <<" is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy points left to attack" << std::endl;

}
