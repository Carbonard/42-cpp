#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Ice::Ice()
: AMateria("ice")
{
	print_debug("Ice default constructor");
}

Ice::Ice(const Ice &other)
: AMateria("ice")
{
	print_debug("Ice copy constructor");
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	print_debug("Ice assignment operator");
	(void) other;
	return (*this);
}

Ice::~Ice()
{
	print_debug("Ice destructor");
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
