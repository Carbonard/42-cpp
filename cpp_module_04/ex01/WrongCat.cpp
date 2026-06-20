#include "WrongCat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

WrongCat::WrongCat()
{
	type = "WrongCat";
	print_debug("WrongCat default constructor");
}

WrongCat::WrongCat(const WrongCat &other)
: WrongAnimal(other)
{
	print_debug("WrongCat copy constructor");
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	print_debug("WrongCat assignment operator");
	return (*this);
}

WrongCat::~WrongCat()
{
	print_debug("WrongCat destructor");
}

void WrongCat::makeSound( void ) const
{
	std::cout << type << ": \"meow\"" << std::endl;
}
