#include "ScalarConverter.hpp"
#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

ScalarConverter::ScalarConverter()
{
	print_debug("ScalarConverter default constructor");
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	print_debug("ScalarConverter copy constructor");
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	print_debug("ScalarConverter assignment operator");
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	print_debug("ScalarConverter destructor");
}

void	ScalarConverter::convert(const std::string &literal)
{
	Scalar s;

	s.setLiteral(literal);
	if (s.isValid())
	{
		std::cout
		<< "char: " << s.toChar() << std::endl
		<< "int: " << s.toInt() << std::endl
		<< "float: " << s.toFloat() << std::endl
		<< "double: " << s.toDouble() << std::endl;
	}
	else
		std::cout << "Invalid literal" << std::endl;
}
