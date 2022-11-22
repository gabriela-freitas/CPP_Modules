
#include "ex01.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("Aleex");

	a.attack("Ju");
	a.takeDamage(5);
	a.takeDamage(5);
	a.attack("ClapClap");
	a.beRepaired(1);
	a.attack("ClapClap");
	return (0);
}
