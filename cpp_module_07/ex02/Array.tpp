#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>
#include <string>

template<typename T>
Array<T>::Array()
{
	_array = new T[0]();
	_size = 0;
}

template<typename T>
Array<T>::Array(const unsigned int n)
{
	_array = new T[n]();
	_size = n;
}

template<typename T>
Array<T>::Array(const Array<T> &other)
{
	this->_array = new T[other._size];
	for (size_t i = 0; i < other._size; i++)
	{
		this->_array[i] = other[i];
	}
	this->_size = other._size;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return *this;
	T* aux = new T[other._size];
	for (size_t i = 0; i < other._size; i++)
	{
		aux[i] = other[i];
	}
	delete[] this->_array;
	this->_array = aux;
	this->_size = other._size;
	return *this;
}

template<typename T>
T& Array<T>::operator[](const int idx) const
{
	if (static_cast<size_t>(idx) >= _size)
		throw std::runtime_error(std::string("invalid index"));
	return _array[idx];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
size_t Array<T>::size() const
{
	return _size;
}

#endif
