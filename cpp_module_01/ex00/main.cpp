#include "Zombie.hpp"

int main(void)
{
	Zombie *foo = newZombie("Foo");
	foo->announce();
	randomChump("Bar");
	foo->announce();
	delete foo;
}
