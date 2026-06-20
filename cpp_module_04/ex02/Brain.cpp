#include "Brain.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[36m" << message << std::endl << "\e[0m";
}

Brain::Brain()
{
	nbIdeas = 0;
	print_debug("Brain default constructor");
}

Brain::Brain(const Brain &other)
{
	print_debug("Brain copy constructor");
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	print_debug("Brain assignment operator");
	for (int i = 0; i < other.nbIdeas; i++)
	{
		ideas[i] = other.ideas[i];
	}
	this->nbIdeas = other.nbIdeas;
	return (*this);
}

Brain::~Brain()
{
	print_debug("Brain destructor");
}

void Brain::haveAnIdea(std::string idea)
{
	if (nbIdeas == 100)
	{
		std::cout << "Full of ideas\n";
		return;
	}
	ideas[nbIdeas] = idea;
	nbIdeas++;
}

void Brain::printIdeas( void )
{
	for (int i = 0; i < nbIdeas; i++)
	{
		std::cout << ideas[i] << std::endl;
	}
}
