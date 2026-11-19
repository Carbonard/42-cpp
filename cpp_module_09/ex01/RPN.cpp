#include "RPN.hpp"
#include <limits>

int safeSum(int a, int b)
{
	long res = static_cast<long>(a) + static_cast<long>(b);
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		throw std::overflow_error("Overflow");
	return static_cast<int>(res);
}

int safeSubs(int a, int b)
{
	long res = static_cast<long>(a) - static_cast<long>(b);
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		throw std::overflow_error("Overflow");
	return static_cast<int>(res);
}

int safeProd(int a, int b)
{
	long res = static_cast<long>(a) * static_cast<long>(b);
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		throw std::overflow_error("Overflow");
	return static_cast<int>(res);
}

int safeDiv(int a, int b)
{
	if (b == 0)
		throw std::domain_error("Division by 0");
	long res = static_cast<long>(a) / static_cast<long>(b);
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		throw std::overflow_error("Overflow");
	return static_cast<int>(res);
}

int calculateResult(const std::string expression)
{
	t_stack s;
	std::string validTokens("+-*/");
	int aux;

	for(std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (std::isdigit(*it))
			s.push(*it - '0');
		else if (validTokens.find(*it) == std::string::npos)
			throw std::invalid_argument(std::string("Invalid token: ") + *it);
		else
		{
			if (s.size() < 2)
				throw std::invalid_argument("Missing numbers or exceeding operations in expression");
			aux = s.top();
			s.pop();
			switch (*it)
			{
				case '+':
					s.top() = safeSum(s.top(), aux);
					break;
				case '*':
					s.top() = safeProd(s.top(), aux);
					break;
				case '-':
					s.top() = safeSubs(s.top(), aux);
					break;
				case '/':
					s.top() = safeDiv(s.top(), aux);
					break;
			}
		}
	}
	if (s.size() > 1)
		throw std::invalid_argument("Exceeding numbers or missing operations in expression");
	if (s.size() < 1)
		throw std::invalid_argument("Empty expression");
	return s.top();
}
