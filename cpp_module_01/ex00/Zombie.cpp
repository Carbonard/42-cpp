#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( std::string zombie_name )
{
	name = zombie_name;
}

Zombie::~Zombie( void )
{
	std::cout << name << " is out of brains" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
