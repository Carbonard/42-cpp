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


template<template <typename, typename> class C>
class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	
	class Link
	{
		public:
			Link();
			Link(int a, int b); // set Link* to NULL
			Link(Link* a, Link* b); // set max_number to respective
			Link(const Link &other);
			Link &operator=(const Link &other);
			~Link();
			Link* max_link;
			Link* min_link;
			int max_number;
	};

	typedef C<Link*, std::allocator<Link*> > LinkContainer_t;

	static void insert (LinkContainer_t& sorted, Link* toInsert, size_t top);
	static size_t search(LinkContainer_t sorted, size_t i, LinkContainer_t& sortedPairs, size_t ins);
	static LinkContainer_t merge(LinkContainer_t& sortedPairs, Link* leftover);
	static void sortLinks(LinkContainer_t& container);
	static void sortContainer(C<int, std::allocator<int> >& container);

public:
	static void computeContainer(int argc, char** argv);
};

size_t getTime();
bool validArg(const std::string arg);

const char* getContainerType(std::vector<int>& c);
const char* getContainerType(std::deque<int>& c);
void printTime(size_t size, const char* container, size_t time);

#include "PmergeMe_utils.tpp"
#include "PmergeMe.tpp"
#include "PmergeMe_algorithm.tpp"

#endif
