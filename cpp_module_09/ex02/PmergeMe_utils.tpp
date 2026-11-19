
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