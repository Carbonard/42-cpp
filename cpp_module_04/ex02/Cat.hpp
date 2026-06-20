#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat: public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void makeSound( void ) const;
	void haveAnIdea(std::string idea);
	void printIdeas( void );
};

#endif
