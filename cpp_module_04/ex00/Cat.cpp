#include "Cat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

Cat::Cat()
{
	type = "Cat";
	print_debug("Cat default constructor");
}

Cat::Cat(const Cat &other)
: Animal(other)
{
	print_debug("Cat copy constructor");
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	print_debug("Cat assignment operator");
	return (*this);
}

Cat::~Cat()
{
	print_debug("Cat destructor");
}

void Cat::makeSound( void ) const
{
	std::cout << type << ": \"meow\"" << std::endl;
}
