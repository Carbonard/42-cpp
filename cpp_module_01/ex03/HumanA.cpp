#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string humanName , Weapon &humanWeapon )
	:weapon(humanWeapon)
{
	name = humanName;
}

void HumanA::attack( void )
{
	std::cout
		<< name
		<< " attacks with their "
		<< weapon.getType()
		<< '\n';
}
