#ifndef HUMANB_CPP
#define HUMANB_CPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB( std::string humanName );
		void setWeapon( Weapon &newWeapon );
		void attack( void );
};

#endif
