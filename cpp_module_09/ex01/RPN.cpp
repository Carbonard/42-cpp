#include "RPN.hpp"

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
			throw std::runtime_error(std::string("Invalid token: ") + *it);
		else
		{
			if (s.size() < 2)
				throw std::runtime_error("Missing numbers or exceeding operations in expression");
			aux = s.top();
			s.pop();
			switch (*it)
			{
			case '+':
				s.top() += aux;
				break;
			case '*':
				s.top() *= aux;
				break;
			case '-':
				s.top() -= aux;
				break;
			case '/':
				s.top() /= aux;
				break;
			}
		}
	}
	if (s.size() > 1)
		throw std::runtime_error("Exceeding numbers or missing operations in expression");
	if (s.size() < 1)
		throw std::runtime_error("Empty expression");
	return s.top();
}
