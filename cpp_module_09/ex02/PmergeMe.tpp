#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"
#include "PmergeMe_utils.tpp"
#include <cmath>
#include <algorithm>

template<typename C>
void checkSorted(C& c)
{
	typename C::const_iterator it = c.begin();
	typename C::const_iterator it_next = c.begin();
	if (it_next != c.end())
		++it_next;
	while (it_next != c.end())
	{
		if (*it > *it_next)
		{
			std::cout << "\e[31mWROOONG!! "<< *it_next <<"\e[0m\n";
			return;
		}
		++it;
		it_next++;
	}
}

template<template <typename, typename> class C>
void PmergeMe::insert (
					C<Link*, std::allocator<Link*> >& sorted,
					Link* toInsert,
					size_t top)
// Binary search to insert elements
{
	size_t bottom = 0;
	do
	{
		size_t mid = (top+bottom)/2;
		if ((mid==0 || toInsert->max_number > sorted[mid-1]->max_number)
			&& toInsert->max_number < sorted[mid]->max_number)
		{
			sorted.insert(sorted.begin()+mid, toInsert);
			return;
		}
		else if (toInsert->max_number > sorted[mid]->max_number)
			bottom = mid+1;
		else
			top = mid;
	}
	while (bottom < top);
	sorted.insert(sorted.begin() + top, toInsert);
	return;
}

template<template <typename, typename> class C>
size_t PmergeMe::search(
					C<Link*, std::allocator<Link*> >	sorted,
					size_t								i,
					C<Link*, std::allocator<Link*> >&	sortedPairs,
					size_t								inserted)
{
	typedef typename C<Link*, std::allocator<Link*> >::iterator t_iterator;
	t_iterator begin = sorted.begin() + i + 1;
	t_iterator end = begin + inserted;
	return std::distance(sorted.begin(), std::find(begin, end, sortedPairs[i]->max_link));
}

template<template <typename, typename> class C>
C<PmergeMe::Link*, std::allocator<PmergeMe::Link*> > PmergeMe::merge(
								C<Link*, std::allocator<Link*> >&	sortedPairs,
								Link*								leftover)
// Create the main chain with the greater numbers of each pair and then insert the lesser numbers
{
	C<Link*, std::allocator<Link*> > sorted;

	// Create main chain
	sorted.push_back(sortedPairs[0]->min_link);
	for (size_t i = 0; i < sortedPairs.size(); i++)
		sorted.push_back(sortedPairs[i]->max_link);
	
	// Insert lesser number of each pair.
	size_t	k=2,
			tkPrev=1,
			tk = std::pow(2, k) - tkPrev;
	size_t inserted = 1;
	while (tk <= sortedPairs.size())
	{
		for (size_t i = tk; i > tkPrev; i--)
		{
			insert( sorted,
					sortedPairs[i-1]->min_link,
					search(sorted, i-1, sortedPairs, inserted) // upper bound for binary search
				);
			inserted++;
		}
		tkPrev = tk;
		k++;
		tk = std::pow(2, k) - tkPrev;
	}
	if (leftover)
		insert(sorted, leftover, sorted.size());
	if (sortedPairs.size() > 0)
		for (size_t i = std::min(tk, sortedPairs.size()); i > tkPrev; i--)
			insert(sorted, sortedPairs[i-1]->min_link, std::distance(sorted.begin(), std::find(sorted.begin() + i, sorted.end(), sortedPairs[i-1]->max_link)));
	
	// Basic shit:

	// for (size_t i = 1; i < sortedPairs.size(); i++)
	// 	insert(sorted, sortedPairs[i]->min_link, sorted.size());
	// if (leftover)
	// 	insert(sorted, leftover, sorted.size());

	return sorted;
}

template<template <typename, typename> class C>
void PmergeMe::sortLinks(C<Link*, std::allocator<Link*> >& container)
// Sort the links by their greater item
{
	if (container.size() == 1)
		return;

	C<Link*, std::allocator<Link*> >	auxContainer;
	Link*								leftover = NULL;

	for (size_t i = 0; i + 1 < container.size(); i+=2)
		// Create sorted linked pairs
		auxContainer.push_back(new Link(container[i], container[i+1]));
	if (container.size()%2 != 0)
		leftover = container.back();

	sortLinks(auxContainer);

	container = merge(auxContainer, leftover);

	for (typename C<Link*, std::allocator<Link*> >::iterator i = auxContainer.begin(); i != auxContainer.end(); i++)
		delete *i;
}

template<template <typename, typename> class C>
void PmergeMe::sortContainer(C<int, std::allocator<int> >& container)
{	
	C<Link*, std::allocator<Link*> > auxContainer;

	for (size_t i = 0; i < container.size(); i++)
		auxContainer.push_back(new Link(container[i], container[i]));
	sortLinks(auxContainer);
	for (size_t i = 0; i < container.size(); i++)
	{
		container[i] = auxContainer[i]->max_number;
		delete auxContainer[i];
	}
}

template<typename C>
void PmergeMe::computeContainer(int argc, char** argv)
{
	C c;

	size_t time = getTime();
	saveArgs(argc, argv, c);
	std::cout << "Before: ";
	printContainer(c);
	sortContainer(c);
	std::cout << "After:  ";
	printContainer(c);
	time = getTime() - time;
	std::cout
		<< "Time to process a range of " << c.size() << " elements "
		<< "with " << getContainerType(c) << " : ";
	if (time < 1000)
		std::cout << time << " usec" << std::endl;
	else if (time < 1000000)
		std::cout << static_cast<double>(time)/1000 << " msec" << std::endl;
	else
		std::cout << static_cast<double>(time)/1000000 << " sec" << std::endl;
	checkSorted(c);
	std::cout << std::endl;
}

#endif
