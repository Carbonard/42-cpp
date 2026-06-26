#include <iostream>
#include <string>
#include <cctype>

std::string	str_to_upper(const std::string &str)
{
	std::string	new_str = str;

	for (size_t i = 0; i < str.length(); i++)
	{
		new_str.at(i) = std::toupper(new_str.at(i));
	}

	return (new_str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else for (int i = 1; i < argc; i++)
	{
		std::cout << str_to_upper(argv[i]);
	}
	std::cout << std::endl;
}
