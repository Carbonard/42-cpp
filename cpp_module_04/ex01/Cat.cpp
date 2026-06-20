#include "Cat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[35m" << message << std::endl << "\e[0m";
}

Cat::Cat()
{
	print_debug("Cat default constructor");
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
: Animal(other)
{
	print_debug("Cat copy constructor");
	brain = new Brain(*(other.brain));
}

Cat &Cat::operator=(const Cat &other)
{
	print_debug("Cat assignment operator");
	Animal::operator=(other);
	delete brain;
	this->brain = new Brain(*(other.brain));
	return (*this);
}

Cat::~Cat()
{
	print_debug("Cat destructor");
	delete brain;
}

void Cat::makeSound( void ) const
{
	std::cout << type << ": \"meow\"" << std::endl;
}

void Cat::haveAnIdea(std::string idea)
{
	brain->haveAnIdea(idea);
}

void Cat::printIdeas( void )
{
	brain->printIdeas();
}
