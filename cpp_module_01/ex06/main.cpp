#include "Harl.hpp"
#include <iostream>

bool valid_level(char *arg)
{
	static const std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == arg)
			return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One argument required\n";
		return (1);
	}
	if (!valid_level(argv[1]))
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}

	Harl h;
	switch (argv[1][0])
	{
	case 'D':
		h.complain("DEBUG");
		h.complain("INFO");
		h.complain("WARNING");
		h.complain("ERROR");
		break;
	case 'I':
		h.complain("INFO");
		h.complain("WARNING");
		h.complain("ERROR");
		break;
	case 'W':
		h.complain("WARNING");
		h.complain("ERROR");
		break;
	case 'E':
		h.complain("ERROR");
		break;
	
	default:
		break;
	}

	return (0);
}
