#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Cure::Cure()
: AMateria("ice")
{
	print_debug("Cure default constructor");
}

Cure::Cure(const Cure &other)
: AMateria("cure")
{
	print_debug("Cure copy constructor");
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	print_debug("Cure assignment operator");
	(void) other;
	return (*this);
}

Cure::~Cure()
{
	print_debug("Cure destructor");
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
