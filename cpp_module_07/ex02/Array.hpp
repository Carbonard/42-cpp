#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
private:
	T*		_array;
	size_t	_size;

public:
	Array();
	Array(const unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	T &operator[](const int idx) const;
	~Array();

	size_t size() const;
};

#include "Array.tpp"

#endif
