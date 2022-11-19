
#include "ex00.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Alex");

	a.attack("Ju");
	a.takeDamage(5);
	a.takeDamage(5);
	a.attack("ClapClap");
	a.beRepaired(1);
	a.attack("ClapClap");
	return (0);
}
