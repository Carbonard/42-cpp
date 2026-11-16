#include "PmergeMe.hpp"
// #include <cstdlib>
#include <sys/time.h>

size_t getTime()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<size_t>(tv.tv_sec) * 1000 * 1000
			+ static_cast<size_t>(tv.tv_usec);
}

bool validArg(const std::string arg)
{
	if (arg.length() > 11)
		return false;
	size_t i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (i == arg.length())
		return false;
	while (i < arg.length())
	{
		if (!std::isdigit(arg[i]))
			return false;
		i++;
	}
	return true;
}
