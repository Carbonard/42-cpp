#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "No arguments provided" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe::computeContainer<t_vector>(argc, argv);
		PmergeMe::computeContainer<t_deque>(argc, argv);
		// computeContainer<t_list>(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

// 40000 -> > 8.5 sec