#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ctrap("CT 1");

	ctrap.attack("Target 1");
	ctrap.takeDamage(7);
	ctrap.beRepaired(4);
	ctrap.takeDamage(7);
	ctrap.beRepaired(2);
	ctrap.attack("Target 1");
	ctrap.takeDamage(3);

	ClapTrap ctrap2("CT 2");
	ctrap2.attack("Target 2");
	ctrap2.takeDamage(9);
	for (int i = 0; i < 6; i++)
	{
		ctrap2.beRepaired(1);
		ctrap2.attack("Target 2");
	}


	ScavTrap trap("ST 1");

	trap.attack("Target 3");
	trap.guardGate();
	trap.takeDamage(70);
	trap.beRepaired(30);
	trap.takeDamage(70);
	trap.beRepaired(2);
	trap.attack("Target 3");
	trap.takeDamage(3);
	trap.guardGate();

	ScavTrap trap2("ST 2");
	trap2.attack("Target 4");
	trap2.takeDamage(9);
	trap2.guardGate();
	for (int i = 0; i < 25; i++)
	{
		trap2.beRepaired(42);
		trap2.attack("Target 4");
	}
}