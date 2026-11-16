#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Required one (end just one) argument" << std::endl;
		return 1;
	}

	t_map btcPrize;
	t_map btcValues;

	try
	{
		readCSV("data.csv", btcPrize);
		printValues(btcPrize, argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
