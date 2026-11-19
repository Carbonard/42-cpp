#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>

template<template <typename, typename> class C>
PmergeMe<C>::PmergeMe(){}
template<template <typename, typename> class C>
PmergeMe<C>::PmergeMe(const PmergeMe &other){(void) other;}
template<template <typename, typename> class C>
PmergeMe<C>& PmergeMe<C>::operator=(const PmergeMe &other){(void) other; return *this;}
template<template <typename, typename> class C>
PmergeMe<C>::~PmergeMe(){}

template<template <typename, typename> class C>
PmergeMe<C>::Link::Link(){}

template<template <typename, typename> class C>
PmergeMe<C>::Link::Link(const Link &other)
{
	this->max_number = other.max_number;
	this->max_link = other.max_link;
	this->min_link = other.min_link;
}

template<template <typename, typename> class C>
typename PmergeMe<C>::Link& PmergeMe<C>::Link::operator=(const Link &other)
{
	this->max_number = other.max_number;
	this->max_link = other.max_link;
	this->min_link = other.min_link;
	return *this;
}

template<template <typename, typename> class C>
PmergeMe<C>::Link::Link(int a, int b)
{
	max_number = std::max(a, b);
	max_link = NULL;
	min_link = NULL;
}

template<template <typename, typename> class C>
PmergeMe<C>::Link::Link(Link* a, Link* b)
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

template<template <typename, typename> class C>
PmergeMe<C>::Link::~Link()
{}

#endif
