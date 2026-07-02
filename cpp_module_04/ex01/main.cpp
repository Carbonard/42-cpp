#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
{
	std::cout << "[ MY TEST 00 ]" << std::endl;
	Dog a;
	Dog b;
	b = a;
	Dog c = b;
	std::cout << "ok"<<std::endl;
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
	std::cout << std::endl << "[ SUBJECT TEST 00 ]" << std::endl;

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
	std::cout << std::endl << "[ MY TEST 01 ]" << std::endl;

	Animal *farm[10];
	for (int i = 0; i < 5; i++)
	{
		farm[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		farm[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		delete farm[i];
	}
{
	Dog a;
	Dog b;
	a.haveAnIdea("Dog idea number 1");
	a.haveAnIdea("Dog idea number 2");
	
	Dog &c = a;
	a = c;
	b = a;
	a.haveAnIdea("Dog idea number 3");
	a.haveAnIdea("Dog idea number 4");
	b.haveAnIdea("Dog idea number 5");
	b.haveAnIdea("Dog idea number 6");
	std::cout << "First Dog:" << std::endl;
	a.printIdeas();
	std::cout << "Second Dog:" << std::endl;
	b.printIdeas();
}
{
	Cat a;
	Cat b;
	a.haveAnIdea("Cat idea number 1");
	a.haveAnIdea("Cat idea number 2");
	b = a;
	a.haveAnIdea("Cat idea number 3");
	a.haveAnIdea("Cat idea number 4");
	b.haveAnIdea("Cat idea number 5");
	b.haveAnIdea("Cat idea number 6");
	std::cout << "First Cat:" << std::endl;
	a.printIdeas();
	std::cout << "Second Cat:" << std::endl;
	b.printIdeas();
}
}
{
	std::cout << std::endl << "[ SUBJECT TEST 01 ]" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

return 0;
}