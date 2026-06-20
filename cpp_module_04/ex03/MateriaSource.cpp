#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

MateriaSource::MateriaSource()
{
	print_debug("MateriaSource default constructor");
	for (int i = 0; i < _maxSlots; i++)
	{
		this->slots[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	print_debug("MateriaSource copy constructor");
	for (int i = 0; i < _maxSlots; i++)
	{
		this->slots[i] = NULL;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	print_debug("MateriaSource assignment operator");
	for (int i = 0; i < _maxSlots; i++)
	{
		if (other.slots[i] != NULL)
		{
			AMateria *tmp = other.slots[i]->clone();
			delete this->slots[i];
			this->slots[i] = tmp;
		}
		else
		{
			delete this->slots[i];
			this->slots[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	print_debug("MateriaSource destructor");
	for (int i = 0; i < _maxSlots; i++)
	{
		delete this->slots[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < _maxSlots; i++)
	{
		if (this->slots[i] == NULL)
		{
			this->slots[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _maxSlots; i++)
	{
		if (this->slots[i] != NULL && this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return (NULL);
}
