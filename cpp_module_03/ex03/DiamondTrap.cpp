#include "DiamondTrap.hpp"
#include <iostream>

#define DEBUG

static void print_debug(std::string message, std::string name)
{
	#ifdef DEBUG
		std::cout
			<< "\e[36m"
			<< message << " (" + name + ")"
			<< std::endl << "\e[0m";
	#endif
}

DiamondTrap::DiamondTrap( void )
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	print_debug("DiamondTrap default constructor", _name);
}

DiamondTrap::DiamondTrap( std::string name )
: ClapTrap(name + "_clap_name"),
  FragTrap(name + "_frag_name"),
  ScavTrap(name + "_scav_name")
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	print_debug("DiamondTrap name constructor", _name);
}

DiamondTrap::DiamondTrap( DiamondTrap &other )
: ClapTrap(other._name + "_clap_name"),
  FragTrap(other._name + "_frag_name"),
  ScavTrap(other._name + "_scav_name")
{
	*this = other;
	print_debug("DiamondTrap copy constructor", _name);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	print_debug("DiamondTrap copy assignment operator", _name);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	print_debug("DiamondTrap destructor", _name);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout
		<< "DiamondTrap " << _name
		<< ": I am " << ClapTrap::_name
		<< std::endl;
		return;
}
