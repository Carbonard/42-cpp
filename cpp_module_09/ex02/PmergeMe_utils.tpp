
#include <cstdlib>

template<typename C>
void saveArgs(int argc, char** argv, C& c)
{
	for (int i = 1; i < argc; i++)
	{
		if (!argv[i][0])
			continue;
		if (!validArg(argv[i]))
			throw std::runtime_error(std::string("Error: invlalid argument: ") + argv[i]);
		c.push_back(std::atoi(argv[i]));
	}
}

template<typename C>
void printContainer(const C& c)
{
	for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename C>
void checkSorted(C& c)
{
	typename C::const_iterator it = c.begin();
	typename C::const_iterator it_next = c.begin();
	if (it_next != c.end())
		++it_next;
	while (it_next != c.end())
	{
		if (*it > *it_next)
		{
			std::cout << "\e[31mWROOONG!! "<< *it_next <<"\e[0m\n";
			return;
		}
		++it;
		it_next++;
	}
}
