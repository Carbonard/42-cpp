#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
{
	Dog a;
	Dog b;
	b = a;
	Dog c = b;
	
	Cat d;
	Cat e;
	e = d;
	Cat f = e;
	
	a.makeSound();
	b.makeSound();
	c.makeSound();
	d.makeSound();
	e.makeSound();
	f.makeSound();
}
{
	std::cout << std::endl << "[ SUBJECT TEST ]" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}
{
	std::cout << std::endl << "[ SUBJECT WRONG_TEST ]" << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* j = new WrongDog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

return 0;
}