#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

AMateria::AMateria()
{
	print_debug("AMateria default constructor");
	this->_type = "Undefined Materia";
}

AMateria::AMateria(std::string const & type)
{
	print_debug("AMateria type constructor");
	this->_type = type;
}

AMateria::AMateria(const AMateria &other)
{
	print_debug("AMateria copy constructor");
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	print_debug("AMateria assignment operator");
	this->_type = other._type;
	return (*this);
}

AMateria::~AMateria()
{
	print_debug("AMateria destructor");
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Somehow, unespecified material is been used with " << target.getName() << std::endl;
}
