#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Character::Character()
{
	print_debug("Character default constructor");
	for (int i = 0; i < _inventorySize; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name)
{
	print_debug("Character name constructor");
	for (int i = 0; i < _inventorySize; i++)
	{
		this->_inventory[i] = NULL;
	}
	_name = name;
}

Character::Character(const Character &other)
{
	print_debug("Character copy constructor");
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	print_debug("Character assignment operator");
	this->_name = other._name;
	for (int i = 0; i < _inventorySize; i++)
	{
		AMateria *tmp = other._inventory[i]->clone();
		delete this->_inventory[i];
		this->_inventory[i] = tmp;
	}
	return (*this);
}

Character::~Character()
{
	print_debug("Character destructor");
	for (int i = 0; i < _inventorySize; i++)
	{
		delete this->_inventory[i];
	}
}


std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
		return;
	this->_inventory[idx] = NULL;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= _inventorySize)
		return (NULL);
	return (this->_inventory[idx]);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _inventorySize)
		return;
	if (this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}
