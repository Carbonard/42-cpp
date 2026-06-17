#include "ClapTrap.hpp"
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
}