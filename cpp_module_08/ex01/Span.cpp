#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span():
_maxSize(0)
{}

Span::Span(const unsigned int N):
_maxSize(static_cast<size_t>(N))
{}

Span::Span(const Span &other):
_maxSize(other._maxSize),
_v(other._v)
{}

Span &Span::operator=(const Span &other)
{
	this->_v = other._v;
	this->_maxSize = other._maxSize;
	return *this;
}

Span::~Span()
{}

void	Span::addNumber(const int n)
{
	if (_v.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	// if (_v.size() == 0)
		_v.push_back(n);
	// else
	// {
	// 	for (t_container::iterator i = _v.begin(); i != _v.end(); i++)
	// 	{
	// 		if (*i > n)
	// 		{
	// 			_v.insert(i, n);
	// 			return;
	// 		}
	// 	}
	// 	_v.push_back(n);
	// }
}

static unsigned int dist(int a, int b)
{
	if (a > b)
		return a-b;
	return b-a;
}

unsigned int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::runtime_error("No span possible");

	std::sort(_v.begin(), _v.end());

	unsigned int ret = dist(_v[0], _v[1]);

	for (t_vector::iterator i = _v.begin(); i != _v.end() && ret > 0; i++)
	{
		if ((i+1) != _v.end() && dist(*i, *(i+1)) < ret)
			ret = dist(*i, *(i+1));
	}

	return ret;
}

unsigned int Span::longestSpan()
{
	return *std::max_element(_v.begin(), _v.end())
		- *std::min_element(_v.begin(), _v.end());
}

void Span::print() const
{
	for (size_t i = 0; i < _v.size(); i++)
	{
		std::cout << _v[i] << " ";
	}
	std::cout << std::endl;
}
