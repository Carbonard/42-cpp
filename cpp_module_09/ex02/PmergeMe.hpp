#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

typedef std::vector<int>	t_vector;
typedef std::deque<int>		t_deque;
typedef std::list<int>		t_list;


class Link
{
public:
	Link();
	Link(int a, int b); // set Link* to NULL
	Link(Link* a, Link* b); // set max_number to respective
	~Link();
	Link* max_link;
	Link* min_link;
	int max_number;
	// size_t index;
};

size_t getTime();
bool validArg(const std::string arg);

// void sortContainer(t_vector& c);
// void sortContainer(t_list& c);

// t_vector sortContainer(t_vector& c);
// t_list sortContainer(t_list& c);

#include "PmergeMe.tpp"

#endif
