#include "Dog.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[35m" << message << std::endl << "\e[0m";
}

Dog::Dog()
{
	print_debug("Dog default constructor");
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
: Animal(other)
{
	print_debug("Dog copy constructor");
	brain = new Brain(*(other.brain));
}

Dog &Dog::operator=(const Dog &other)
{
	print_debug("Dog assignment operator");
	Animal::operator=(other);
	Brain *tmp = new Brain(*(other.brain));
	delete brain;
	this->brain = tmp;
	return (*this);
}

Dog::~Dog()
{
	print_debug("Dog destructor");
	delete brain;
}

void Dog::makeSound( void ) const
{
	std::cout << type << ": \"woof\"" << std::endl;
}

void Dog::haveAnIdea(std::string idea)
{
	brain->haveAnIdea(idea);
}

void Dog::printIdeas( void )
{
	brain->printIdeas();
}
