#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string humanName )
{
	name = humanName;
}

void HumanB::setWeapon( Weapon &newWeapon )
{
	weapon = &newWeapon;
}

void HumanB::attack( void )
{
	std::cout
		<< name
		<< " attacks with their "
		<< weapon->getType()
		<< '\n';
}
