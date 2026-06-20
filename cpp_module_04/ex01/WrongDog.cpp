#include "WrongDog.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

WrongDog::WrongDog()
{
	type = "WrongDog";
	print_debug("WrongDog default constructor");
}

WrongDog::WrongDog(const WrongDog &other)
: WrongAnimal(other)
{
	print_debug("WrongDog copy constructor");
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	WrongAnimal::operator=(other);
	print_debug("WrongDog assignment operator");
	return (*this);
}

WrongDog::~WrongDog()
{
	print_debug("WrongDog destructor");
}

void WrongDog::makeSound( void ) const
{
	std::cout << type << ": \"woof\"" << std::endl;
}
