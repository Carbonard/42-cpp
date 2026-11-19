#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other){(void) other;}
PmergeMe& PmergeMe::operator=(const PmergeMe &other){(void) other; return *this;}
PmergeMe::~PmergeMe(){}


PmergeMe::Link::Link(){}

PmergeMe::Link::Link(const Link &other)
{
	this->max_number = other.max_number;
	this->max_link = other.max_link;
	this->min_link = other.min_link;
}

PmergeMe::Link& PmergeMe::Link::operator=(const Link &other)
{
	this->max_number = other.max_number;
	this->max_link = other.max_link;
	this->min_link = other.min_link;
	return *this;
}

PmergeMe::Link::Link(int a, int b)
{
	max_number = std::max(a, b);
	max_link = NULL;
	min_link = NULL;
}

PmergeMe::Link::Link(Link* a, Link* b)
{
	if (a->max_number > b->max_number)
	{
		max_number = a->max_number;
		max_link = a;
		min_link = b;
	}
	else
	{
		max_number = b->max_number;
		max_link = b;
		min_link = a;
	}
}

PmergeMe::Link::~Link()
{}
