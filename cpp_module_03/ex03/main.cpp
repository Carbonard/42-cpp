#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ctrap("CT_1");

	ctrap.attack("Target 1");
	ctrap.takeDamage(7);
	ctrap.beRepaired(4);
	ctrap.takeDamage(7);
	ctrap.beRepaired(2);
	ctrap.attack("Target 1");
	ctrap.takeDamage(3);

	ClapTrap ctrap2("CT_2");
	ctrap2.attack("Target 2");
	ctrap2.takeDamage(9);
	for (int i = 0; i < 6; i++)
	{
		ctrap2.beRepaired(1);
		ctrap2.attack("Target 2");
	}


	ScavTrap strap("ST_1");

	strap.attack("Target 3");
	strap.guardGate();
	strap.takeDamage(70);
	strap.beRepaired(30);
	strap.takeDamage(70);
	strap.beRepaired(2);
	strap.attack("Target 3");
	strap.takeDamage(3);
	strap.guardGate();

	ScavTrap strap2("ST_2");
	strap2.attack("Target 4");
	strap2.takeDamage(9);
	strap2.guardGate();
	for (int i = 0; i < 20; i++)
	{
		strap2.beRepaired(42);
		strap2.attack("Target 4");
		strap2.guardGate();
	}


	FragTrap ftrap("FT_1");

	ftrap.attack("Target 5");
	ftrap.highFivesGuys();
	ftrap.takeDamage(70);
	ftrap.beRepaired(30);
	ftrap.takeDamage(70);
	ftrap.beRepaired(2);
	ftrap.attack("Target 5");
	ftrap.takeDamage(3);
	ftrap.highFivesGuys();

	FragTrap ftrap2("FT_2");
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


	DiamondTrap dtrap("DT_1");

	dtrap.attack("Target 7");
	dtrap.guardGate();
	dtrap.highFivesGuys();
	dtrap.whoAmI();
	dtrap.takeDamage(70);
	dtrap.beRepaired(30);
	dtrap.takeDamage(70);
	dtrap.beRepaired(2);
	dtrap.attack("Target 7");
	dtrap.takeDamage(3);
	dtrap.highFivesGuys();

	DiamondTrap dtrap2("DT_2");
	dtrap2.attack("Target 8");
	dtrap2.takeDamage(9);
	dtrap2.attack("Target 8");
	dtrap2.highFivesGuys();
	dtrap2.attack("Target 8");
	for (int i = 0; i < 15; i++)
	{
		dtrap2.beRepaired(42);
		dtrap.guardGate();
		dtrap.highFivesGuys();
		dtrap.whoAmI();
	}
}
