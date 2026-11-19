#include "PmergeMe.hpp"

template<template <typename, typename> class C>
size_t PmergeMe<C>::insert (
						LinkContainer_t& sorted,
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
			sorted.insert(sorted.begin() + mid, toInsert);
			return mid;
		}
		else if (toInsert->max_number > sorted[mid]->max_number)
			bottom = mid+1;
		else
			top = mid;
	}
	while (bottom < top);
	sorted.insert(sorted.begin() + top, toInsert);
	return top;
}

template<template <typename, typename> class C>
typename PmergeMe<C>::LinkContainer_t PmergeMe<C>::merge(
														LinkContainer_t&	sortedPairs,
														Link*				leftover)
// Create the main chain with the greater numbers of each pair and then insert the lesser numbers
{
	LinkContainer_t sorted;

	// Create main chain
	sorted.push_back(sortedPairs[0]->min_link);
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		sortedPairs[i]->sortedIndex = sorted.size();
		sorted.push_back(sortedPairs[i]->max_link);
	}
	
	// Insert lesser number of each pair.
	size_t	k=2,
			tkPrev=1,
			tk = std::pow(2, k) - tkPrev,
			idx;
	while (tk <= sortedPairs.size())
	{
		for (size_t i = tk; i > tkPrev; i--)
		{
			idx = insert(sorted,
								sortedPairs[i-1]->min_link,
								sortedPairs[i-1]->sortedIndex + tkPrev-1
							);
			// for (size_t p = sortedPairs.size(); p > tk ; p--)
			// 	sortedPairs[p-1]->sortedIndex++;
			for (size_t p = i-1; p > tkPrev && sortedPairs[p-1]->sortedIndex + tkPrev-1 >= idx; p--)
				sortedPairs[p-1]->sortedIndex++;
		}
		tkPrev = tk;
		k++;
		tk = std::pow(2, k) - tkPrev;
	}
	if (leftover)
	{
		idx = insert(sorted, leftover, sorted.size());
		for (size_t p = sortedPairs.size(); p > tkPrev && sortedPairs[p-1]->sortedIndex + tkPrev-1 >= idx; p--)
			sortedPairs[p-1]->sortedIndex++;
	}
	if (sortedPairs.size() > 0)
		for (size_t i = std::min(tk, sortedPairs.size()); i > tkPrev; i--)
		{
			idx = insert(sorted, sortedPairs[i-1]->min_link, sorted.size());
			for (size_t p = sortedPairs.size(); p > tkPrev && sortedPairs[p-1]->sortedIndex + tkPrev-1 >= idx; p--)
				sortedPairs[p-1]->sortedIndex++;
		}
	
	// Basic shit:

	// for (size_t i = 1; i < sortedPairs.size(); i++)
	// 	insert(sorted, sortedPairs[i]->min_link, sorted.size());
	// if (leftover)
	// 	insert(sorted, leftover, sorted.size());

	return sorted;
}

template<template <typename, typename> class C>
void PmergeMe<C>::sortLinks(LinkContainer_t& container)
// Sort the links by their greater item
{
	if (container.size() == 1)
		return;

	LinkContainer_t	auxContainer;
	Link*			leftover = NULL;

	for (size_t i = 0; i + 1 < container.size(); i+=2)
		// Create sorted linked pairs
		auxContainer.push_back(new Link(container[i], container[i+1]));
	if (container.size()%2 != 0)
		leftover = container.back();

	sortLinks(auxContainer);

	container = merge(auxContainer, leftover);

	for (typename LinkContainer_t::iterator i = auxContainer.begin(); i != auxContainer.end(); i++)
		delete *i;
}

template<template <typename, typename> class C>
void PmergeMe<C>::sortContainer(C<int, std::allocator<int> >& container)
{	
	LinkContainer_t auxContainer;

	for (size_t i = 0; i < container.size(); i++)
		auxContainer.push_back(new Link(container[i], container[i]));
	sortLinks(auxContainer);
	for (size_t i = 0; i < container.size(); i++)
	{
		container[i] = auxContainer[i]->max_number;
		delete auxContainer[i];
	}
}

template<template <typename, typename> class C>
void PmergeMe<C>::computeContainer(int argc, char** argv)
{
	C<int, std::allocator<int> > c;

	size_t initialTime = getTime();
	saveArgs(argc, argv, c);

	// std::cout << "Before: ";
	// printContainer(c);

	sortContainer(c);

	// std::cout << "After:  ";
	// printContainer(c);

	printTime(c.size(), getContainerType(c), getTime() - initialTime);

	checkSorted(c);
}
