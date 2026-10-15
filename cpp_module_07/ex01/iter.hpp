#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename S>
void iter(T *array, const size_t N, S function)
{
	for (size_t i = 0; i < N; i++)
		function(array[i]);
}

#endif
