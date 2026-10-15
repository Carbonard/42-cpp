#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T &container, int target)
{
	typename T::iterator res = std::find(container.begin(), container.end(), target);
	if (res == container.end())
		throw std::runtime_error("Number not found");
	return res;
}

#endif
