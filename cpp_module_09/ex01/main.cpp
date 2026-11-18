#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cerr << "One (and just one) argument is required" << std::endl;
	else try
	{
		int result = calculateResult(argv[1]);

		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
