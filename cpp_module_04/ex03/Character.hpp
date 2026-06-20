#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character: public ICharacter
{
private:
	std::string _name;
	static const int _inventorySize = 4;
	AMateria *_inventory[_inventorySize];

public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	AMateria *getMateria(int idx) const;
	void use(int idx, ICharacter& target);
};

#endif
