#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string humanName )
{
	name = humanName;
	weapon = NULL;
}

void HumanB::setWeapon( Weapon &newWeapon )
{
	weapon = &newWeapon;
}

void HumanB::attack( void )
{
	if (weapon)
	{
		std::cout
			<< name
			<< " attacks with their "
			<< weapon->getType()
			<< std::endl;
	}
	else
	{
		std::cout
			<< name
			<< " tries to attack... But has no weapon"
			<< std::endl;
	}
}
