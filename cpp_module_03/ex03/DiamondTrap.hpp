#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap &other );
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap( void );

	void attack(const std::string& target);
	void whoAmI( void );
};

#endif
