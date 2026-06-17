#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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


	ScavTrap strap("ST 1");

	strap.attack("Target 3");
	strap.guardGate();
	strap.takeDamage(70);
	strap.beRepaired(30);
	strap.takeDamage(70);
	strap.beRepaired(2);
	strap.attack("Target 3");
	strap.takeDamage(3);
	strap.guardGate();

	ScavTrap strap2("ST 2");
	strap2.attack("Target 4");
	strap2.takeDamage(9);
	strap2.guardGate();
	for (int i = 0; i < 20; i++)
	{
		strap2.beRepaired(42);
		strap2.attack("Target 4");
		strap2.guardGate();
	}


	FragTrap ftrap("FT 1");

	ftrap.attack("Target 5");
	ftrap.highFivesGuys();
	ftrap.takeDamage(70);
	ftrap.beRepaired(30);
	ftrap.takeDamage(70);
	ftrap.beRepaired(2);
	ftrap.attack("Target 5");
	ftrap.takeDamage(3);
	ftrap.highFivesGuys();

	FragTrap ftrap2("FT 2");
	ftrap2.attack("Target 6");
	ftrap2.takeDamage(9);
	ftrap2.attack("Target 6");
	ftrap2.highFivesGuys();
	ftrap2.attack("Target 6");
	for (int i = 0; i < 35; i++)
	{
		ftrap2.beRepaired(42);
		ftrap2.attack("Target 6");
		ftrap2.highFivesGuys();
	}
}