#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
	int nbIdeas;

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	virtual ~Brain();

	void haveAnIdea(std::string idea);
	void printIdeas( void );
};

#endif
