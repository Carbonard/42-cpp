#ifndef HUMANA_CPP
#define HUMANA_CPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA( std::string humanName , Weapon &humanWeapon );
		void setWeapon( Weapon newWeapon );
		void attack( void );
};

#endif
