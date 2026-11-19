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
		PmergeMe<std::vector>::computeContainer(argc, argv);
		PmergeMe<std::deque>::computeContainer(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
