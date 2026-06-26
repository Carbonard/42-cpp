#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

bool isNumeric(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

int main()
{
	PhoneBook pb;
	std::string input;
	do
	{
		std::cin.clear();
		std::cout << "\nEnter a command (ADD / SEARCH / EXIT)\n> ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "ADD")
		{
			try
			{
				pb.add_new_contact();
			}
			catch (const std::runtime_error &e)
			{
				std::cout << e.what();
			}
		}
		if (input == "SEARCH")
		{
			if (pb.is_empty())
			{
				std::cout << "Your phone book is empty\n";
				continue;
			}
			std::cout << "Select an index:\n";
			pb.display_all();
			std::cout << "Index: ";
			std::string index;
			std::getline(std::cin, index);
			try
			{
				if (!isNumeric(index))
					throw(std::runtime_error("Non-numeric index"));
				if (index.empty())
					throw(std::runtime_error("Empty index"));
				pb.display_one(std::atoi(index.data()));
			}
			catch (const std::runtime_error &e)
			{
				std::cout << std::endl << e.what() << std::endl;
			}

		}
	} while(input != "EXIT" && !std::cin.eof());
	return 0;
}