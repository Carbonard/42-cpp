#include "Animal.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Animal::Animal()
{
	print_debug("Animal default constructor");
	type = "Random animal";
}

Animal::Animal(const Animal &other)
{
	print_debug("Animal copy constructor");
	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	print_debug("Animal assignment operator");
	type = other.type;
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

