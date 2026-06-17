#include "ScavTrap.hpp"
#include <iostream>

#define DEBUG

static void print_debug(std::string message, std::string name)
{
	#ifdef DEBUG
		std::cout
			<< "\e[35m"
			<< message << " (" + name + ")"
			<< std::endl << "\e[0m";
	#endif
}

ScavTrap::ScavTrap( void )
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	print_debug("ScavTrap default constructor", _name);
}

ScavTrap::ScavTrap( std::string name )
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	print_debug("ScavTrap name constructor", _name);
}

ScavTrap::ScavTrap( ScavTrap &other )
: ClapTrap(other._name)
{
	*this = other;
	print_debug("ScavTrap copy constructor", _name);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	print_debug("ScavTrap copy assignment operator", _name);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	print_debug("ScavTrap destructor", _name);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " is dead :("
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " has no more energy points :("
			<< std::endl;
			return;
	}
	std::cout
		<< "ScavTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate( void )
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " is dead :("
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "ScavTrap " << _name
			<< " has no more energy points :("
			<< std::endl;
			return;
	}
	std::cout
	<< "ScavTrap " << _name
	<< " is now in Gate keeper mode"
	<< std::endl;
	_energyPoints--;
}
