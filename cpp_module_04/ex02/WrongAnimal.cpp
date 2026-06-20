#include "WrongAnimal.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	print_debug("WrongAnimal default constructor");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	type = other.type;
	print_debug("WrongAnimal copy constructor");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	print_debug("WrongAnimal assignment operator");
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	print_debug("WrongAnimal destructor");
}

std::string WrongAnimal::getType( void ) const
{
	return (type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << type << ": *unrecognizable sounds*" << std::endl;
}

