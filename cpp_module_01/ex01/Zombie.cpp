#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( std::string zombieName )
{
	name = zombieName;
}

Zombie::Zombie( void )
{
	name = "Generic Zombie";
}

Zombie::~Zombie( void )
{
	std::cout << name << " is out of brains\n";
}

void Zombie::setName( std::string zombieName )
{
	name = zombieName;
}

void Zombie::announce( void )
{
	std::cout << name <<": BraiiiiiiinnnzzzZ...\n";
}
