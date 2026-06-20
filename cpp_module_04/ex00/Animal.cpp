#include "Animal.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

Animal::Animal()
{
	type = "Random animal";
	print_debug("Animal default constructor");
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	print_debug("Animal copy constructor");
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	print_debug("Animal assignment operator");
	return (*this);
}

Animal::~Animal()
{
	print_debug("Animal destructor");
}

std::string Animal::getType( void ) const
{
	return (type);
}

void Animal::makeSound( void ) const
{
	std::cout << type << ": *unrecognizable sounds*" << std::endl;
}

