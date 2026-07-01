#include "ClapTrap.hpp"
#include <iostream>

#define DEBUG

static void print_debug(std::string message, std::string name)
{
	#ifdef DEBUG
		std::cout
			<< "\e[33m"
			<< message << " (" + name + ")"
			<< std::endl << "\e[0m";
	#endif
}

ClapTrap::ClapTrap( void )
{
	_name = "Generic clap trap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	print_debug("ClapTrap default constructor", _name);
}

ClapTrap::ClapTrap( std::string name )
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	print_debug("ClapTrap name constructor", _name);
}

ClapTrap::ClapTrap( ClapTrap &other )
{
	*this = other;
	print_debug("ClapTrap copy constructor", _name);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	print_debug("ClapTrap copy assignment operator", _name);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	print_debug("ClapTrap destructor", _name);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " is dead, cannot attack"
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " has no more energy points, cannot attack"
			<< std::endl;
			return;
	}
	std::cout
		<< "ClapTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " is already dead, cannot lose more damage"
			<< std::endl;
			return;
	}
	std::cout
		<< "ClapTrap " << _name
		<< " loses " << amount << " hit points!"
		<< std::endl;
	if (_hitPoints > amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " is dead, cannot be repaired"
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "ClapTrap " << _name
			<< " has no more energy points, cannot be repaired"
			<< std::endl;
			return;
	}
	std::cout
		<< "ClapTrap " << _name
		<< " regains " << amount << " hit points!"
		<< std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
