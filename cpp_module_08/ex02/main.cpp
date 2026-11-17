#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "-------- List --------" << std::endl;
{
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
	std::cout << "-------- Mutant iterator --------" << std::endl;
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
	std::cout << "------- Mutant const iterator ---------" << std::endl;
{
	MutantStack<int> s;
	s.push(1);
	s.push(2);
	s.push(4);
	s.push(8);
	s.push(16);
	s.push(32);
	const MutantStack<int> m(s);
	MutantStack<int>::const_iterator it = m.begin();
	MutantStack<int>::const_iterator ite = m.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
	std::cout << "------- Mutant reverse iterator ---------" << std::endl;
{
	MutantStack<int> m;
	m.push(1);
	m.push(2);
	m.push(4);
	m.push(8);
	m.push(16);
	m.push(32);
	MutantStack<int>::reverse_iterator it = m.rbegin();
	MutantStack<int>::reverse_iterator ite = m.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
	return 0;
}