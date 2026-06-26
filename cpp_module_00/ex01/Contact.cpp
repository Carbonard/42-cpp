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
		if (std::cin.eof())
			throw std::runtime_error("\nContact input aborted");
	} while (input.empty());
	return input;
}

static bool isPhone(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i])
			&& input[i] != '-'
			&& input[i] != '+'
			&& input[i] != ' ')
			return false;
	}
	return true;
	
}

void Contact::ask_for_input(void)
{
	_first_name = read_input("First name: ");
	_last_name = read_input("Last name: ");
	_nickname = read_input("Nickname: ");
	do
	{
		_phone_number = read_input("Phone number: ");
	} while (!isPhone(_phone_number) && !std::cin.eof());
	_darkest_secret = read_input("Darkest secret: ");
}

void Contact::display(void) const
{
	std::cout << std::endl;
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

std::string Contact::get_first_name(void) const
{
	return _first_name;
}

std::string Contact::get_last_name(void) const
{
	return _last_name;
}

std::string Contact::get_nickname(void) const
{
	return _nickname;
}

std::string Contact::get_phone_number(void) const
{
	return _phone_number;
}
