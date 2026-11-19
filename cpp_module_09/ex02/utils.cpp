#include "PmergeMe.hpp"
#include <sys/time.h>
#include <limits>

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
	long n = std::atol(arg.c_str());
	if (n > std::numeric_limits<int>::max()
	 || n < std::numeric_limits<int>::min())
		return false;
	return true;
}

std::string getContainerType(std::vector<int>& c)
{
	(void) c;
	return "std::vector";
}

std::string getContainerType(std::deque<int>& c)
{
	(void) c;
	return "std::deque";
}
