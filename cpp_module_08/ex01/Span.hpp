#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <cstddef>

typedef std::vector<int> t_vector;

class Span
{
private:
	size_t		_maxSize;
	t_vector	_v;

public:
	Span();
	Span(const unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void			addNumber(const int n);
	template<typename T>
	void			addNumbers(const T& container);
	template<typename it>
	void			addRange(it begin,
							it end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			print() const;
};


template<typename T>
void Span::addNumbers(const T& container)
{
	this->addRange(container.begin(), container.end());
}

template<typename it>
void Span::addRange(it begin, it end)
{
	for(it i = begin; i != end; i++)
	{
		this->addNumber(static_cast<int>(*i));
	}
}

#endif
