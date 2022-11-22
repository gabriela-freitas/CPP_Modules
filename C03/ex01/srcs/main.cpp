
#include "ex01.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("Alex");

	a.attack("Ju");
	a.takeDamage(5);
	a.takeDamage(5);
	a.attack("ClapClap");
	a.beRepaired(1);
	a.attack("ClapClap");
	return (0);
}
