#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

static std::string read_input(const std::string prompt)
{
	std::string input;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input == "");
	return (input);
}

void Contact::ask_for_input(void)
{
	_first_name = read_input("First name: ");
	_last_name = read_input("Last name: ");
	_nickname = read_input("Nickname: ");
	_phone_number = read_input("Phone number: ");
	_darkest_secret = read_input("Darkest secret: ");
}

void Contact::display(void) const
{
	std::cout << "First name: " << _first_name << '\n';
	std::cout << "Last name: " << _last_name << '\n';
	std::cout << "Nickname: " << _nickname << '\n';
	std::cout << "Phone number: " << _phone_number << '\n';
	std::cout << "Darkest secret: " << _darkest_secret << '\n';
}

std::string Contact::get_first_name(void) const
{
	return(_first_name);
}

std::string Contact::get_last_name(void) const
{
	return(_last_name);
}

std::string Contact::get_nickname(void) const
{
	return(_nickname);
}

std::string Contact::get_phone_number(void) const
{
	return(_phone_number);
}
