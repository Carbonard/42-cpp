#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_saved = 0;
}

bool PhoneBook::is_empty(void) const
{
	return (_saved == 0);
}

static std::string truncate(const std::string &str)
{
	if (str.length() > 10)
	{
		std::string ret;
		ret = str.substr(0, 9);
		ret.push_back('.');
		return (ret);
	}
	return (str);
}

static void print_cell(const std::string &str)
{
	std::cout
		<< std::setw(10)
		<< std::right
		<< truncate(str)
		<< '|';
}

static void print_first_row(const std::string strings[4])
{
	for (int i = 0; i < 4; i++)
		print_cell(strings[i]);
	std::cout << '\n';
}

static void print_row(const int &index, const std::string strings[3])
{
	std::cout
		<< std::setw(10)
		<< std::right
		<< index
		<< '|';
	for (int i = 0; i < 3; i++)
		print_cell(strings[i]);
	std::cout << '\n';
}

void PhoneBook::display_all(void) const
{
	std::string first_row[4] = {"index","First Name","Last Name","Nickname"};
	print_first_row(first_row);
	for (int i = 0; i < _saved; i++)
	{
		std::string row[3] = {_contacts[i].get_first_name(), _contacts[i].get_last_name(), _contacts[i].get_nickname()};
		print_row(i, row);
	}
}

void PhoneBook::display_one(int n) const
{
	if (n >= _saved || n < 0)
	{
		std::cerr << "Invalid index\n";
		return;
	}
	_contacts[n].display();
}

void PhoneBook::add(const Contact &c)
{
	if (_saved >= MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			_contacts[i] = _contacts[i+1];
		_saved--;
	}
	_contacts[_saved] = c;
	_saved++;
}
