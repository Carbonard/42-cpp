#include "Zombie.hpp"

int main(void)
{
	Zombie *paco = newZombie("Paco");
	randomChump("Eladio");
	paco->announce();
	delete paco;
}
