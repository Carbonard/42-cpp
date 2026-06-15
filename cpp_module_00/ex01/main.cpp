#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	PhoneBook pb;
	std::string input = "\n";
	do
	{
		std::cout << "\nEnter a command (ADD / SEARCH / EXIT)\n> ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			Contact contact;
			contact.ask_for_input();
			pb.add(contact);
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
			int i;
			try
			{
				for (size_t i=0; i < index.length(); i++)
				{
					if (!std::isdigit(index[i]))
						throw(1);
				}
				i = std::atoi(index.data());
			}
			catch (...)
			{
				i = -1;
			}
			std::cout << '\n';
			pb.display_one(i);

		}
	} while(input != "EXIT");
	return (0);
}
