#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>


static AMateria *floor[20];
static int floorIdx = 0;

static void throwToFloor(Character *c, int i)
{
	if (floorIdx == 20)
		return;
	floor[floorIdx] = c->getMateria(i);
	floorIdx++;
	c->unequip(i);
}

int main()
{
{
	std::cout << "[ SUBJECT TEST ]" << std::endl << std::endl;

	IMateriaSource* src = new MateriaSource();
	AMateria *temp = new Ice();
	src->learnMateria(temp);
	delete temp;
	temp = new Cure;
	src->learnMateria(temp);
	delete temp;

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}
{
	std::cout << std::endl << "[ MY TEST ]" << std::endl << std::endl;

	MateriaSource* tmp_src = new MateriaSource;
	AMateria *temp;

	temp = new Ice;
	tmp_src->learnMateria(temp);
	delete temp;
	temp = new Cure;
	tmp_src->learnMateria(temp);
	delete temp;

	MateriaSource *src = new MateriaSource(*tmp_src);
	delete tmp_src;

	temp = new Ice;
	src->learnMateria(temp);
	delete temp;
	temp = new Cure;
	src->learnMateria(temp);
	delete temp;
	temp = new Ice;
	src->learnMateria(temp);
	delete temp;
	temp = new Cure;
	src->learnMateria(temp);
	delete temp;

	Character *john = new Character("John");
	Character *jack = new Character("Jack");

	for (int i = 0; i < 6; i++)
	{
		temp = src->createMateria("ice");
		john->equip(temp);
		if (i >= 4) // This should not be equiped
			delete temp;
	}
	for (int i = 0; i < 6; i++)
	{
		john->use(i, *jack);
	}

	throwToFloor(john, 1);
	throwToFloor(john, 3);
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		john->use(i, *jack);
	}

	john->equip(src->createMateria("cure"));
	john->equip(src->createMateria("cure"));
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		john->use(i, *jack);
	}
	
	delete src;
	delete john;
	delete jack;
	for (int i = 0; i < floorIdx; i++)
	{
		delete floor[i];
	}

}
	return 0;
}
