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

	template<template <typename, typename> class C>
	static void insert (C<Link*, std::allocator<Link*> >& sorted, Link* toInsert, size_t top);

	template<template <typename, typename> class C>
	static size_t search(C<Link*, std::allocator<Link*> > sorted, size_t i, C<Link*, std::allocator<Link*> >& sortedPairs, size_t ins);

	template<template <typename, typename> class C>
	static C<Link*, std::allocator<Link*> > merge(C<Link*, std::allocator<Link*> >& sortedPairs, Link* leftover);

	template<template <typename, typename> class C>
	static void sortLinks(C<Link*, std::allocator<Link*> >& container);

	template<template <typename, typename> class C>
	static void sortContainer(C<int, std::allocator<int> >& container);

public:
	template<typename T>
	static void computeContainer(int argc, char** argv);
};

size_t getTime();
bool validArg(const std::string arg);

std::string getContainerType(std::vector<int>& c);
std::string getContainerType(std::deque<int>& c);

#include "PmergeMe.tpp"

#endif
