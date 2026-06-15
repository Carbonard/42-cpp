#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string	str_to_upper(const std::string &str)
{
	std::string	new_str = str;

	for (std::string::iterator c = new_str.begin(); c < new_str.end(); c++)
		*c = std::toupper(*c);

	return (new_str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string upper_arg = str_to_upper("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << upper_arg;
	}
	else for (int i = 1; i < argc; i++)
	{
		// std::string arg = ;
		std::string upper_arg = str_to_upper(argv[i]);
		std::cout << upper_arg;
	}
	std::cout << '\n';
}
