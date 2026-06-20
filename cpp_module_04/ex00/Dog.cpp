#include "Dog.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

Dog::Dog()
{
	type = "Dog";
	print_debug("Dog default constructor");
}

Dog::Dog(const Dog &other)
: Animal(other)
{
	print_debug("Dog copy constructor");
}

Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	print_debug("Dog assignment operator");
	return (*this);
}

Dog::~Dog()
{
	print_debug("Dog destructor");
}

void Dog::makeSound( void ) const
{
	std::cout << type << ": \"woof\"" << std::endl;
}
