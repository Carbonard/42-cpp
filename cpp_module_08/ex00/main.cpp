#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

int main()
{
{
	typedef std::list<int> container;
	container c;
	c.push_back(4);
	c.push_back(2);
	c.push_back(0);
	c.push_back(42);
	c.push_back(32);
	c.push_back(42);
	try
	{
		int a = 42;
		*(easyfind(c, a)) = -42;
		for (container::iterator i = c.begin(); i != c.end(); i++)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		easyfind(c, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
{
	typedef std::vector<int> container;
	container c;
	c.push_back(4);
	c.push_back(2);
	c.push_back(0);
	c.push_back(42);
	c.push_back(32);
	c.push_back(42);
	try
	{
		int a = 42;
		*(easyfind(c, a)) = -42;
		for (container::iterator i = c.begin(); i != c.end(); i++)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		easyfind(c, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
{
	typedef std::deque<int> container;
	container c;
	c.push_back(4);
	c.push_back(2);
	c.push_back(0);
	c.push_back(42);
	c.push_back(32);
	c.push_back(42);
	try
	{
		int a = 42;
		*(easyfind(c, a)) = -42;
		for (container::iterator i = c.begin(); i != c.end(); i++)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		easyfind(c, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
	return 0;
}