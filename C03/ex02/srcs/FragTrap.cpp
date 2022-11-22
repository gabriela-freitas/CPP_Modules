
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	_name = name;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& param) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->_name = param.get_name();
	return (*this);
}

FragTrap::FragTrap(const FragTrap& param) {
	*this = param;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap" << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name <<" requests High Fives!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " has no energy points left to attack" << std::endl;

}
