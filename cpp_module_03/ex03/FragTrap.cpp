#include "FragTrap.hpp"
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

FragTrap::FragTrap( void )
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	print_debug("FragTrap default constructor", _name);
}

FragTrap::FragTrap( std::string name )
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	print_debug("FragTrap name constructor", _name);
}

FragTrap::FragTrap( FragTrap &other )
: ClapTrap(other._name)
{
	*this = other;
	print_debug("FragTrap copy constructor", _name);
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	print_debug("FragTrap copy assignment operator", _name);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	print_debug("FragTrap destructor", _name);
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "FragTrap " << _name
			<< " is dead :("
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "FragTrap " << _name
			<< " has no more energy points :("
			<< std::endl;
			return;
	}
	std::cout
		<< "FragTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys( void )
{
	if (_hitPoints == 0)
	{
		std::cout
			<< "FragTrap " << _name
			<< " is dead :("
			<< std::endl;
			return;
	}
	if (_energyPoints == 0)
	{
		std::cout
			<< "FragTrap " << _name
			<< " has no more energy points :("
			<< std::endl;
			return;
	}
	std::cout
	<< "FragTrap " << _name
	<< ": \"Hey guys, high fives!\" :D"
	<< std::endl;
	_energyPoints--;
}
