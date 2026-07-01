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
		std::cout << "One argument required" << std::endl;
		return (1);
	}
	if (!valid_level(argv[1]))
	{
		std::cout
			<< "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		return (0);
	}

	Harl h;
	switch (argv[1][0])
	{
		case 'D':
			h.complain("DEBUG");
			// fall-through
		case 'I':
			h.complain("INFO");
			// fall-through
		case 'W':
			h.complain("WARNING");
			// fall-through
		case 'E':
			h.complain("ERROR");
			// fall-through
		
		default:
			break;
	}

	return (0);
}
