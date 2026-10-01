#include "ScalarConverter.hpp"
#include <iostream>

void	test(std::string literal)
{
	std::cout << std::endl << "\e[32mTesting " << literal << "\e[0m" << std::endl;
	ScalarConverter::convert(literal);
}

void	myTests()
{
	test("");
	test("0");
	test("42");
	test("+42");
	test("-42");
	test("42f");
	test("+42f");
	test("-42f");
	test("42.0");
	test("-42.0");
	test("+42.5");
	test("+42.5f");
	test("-42.5");
	test("-42.5f");
	test("a");
	test("'a'");
	test("12345678900");
	test("999999999999999999999999999999999999999999");
	test("-999999999999999999999999999999999999999999");
	test("2147483647");
	test("2147483648");
	test("-2147483648");
	test("-2147483649");
	test("inff");
	test("+inff");
	test("-inff");
	test("nanf");
	test("inf");
	test("+inf");
	test("-inf");
	test("nan");
	test("100000");
	test("1000000");
	test("0.00001");
	test("0.0001");
	test("-100000");
	test("-1000000");
	test("-0.00001");
	test("-0.0001");
}

int main(int argc, char **argv)
{
	if (argc == 1)
		myTests();
	else for (int i = 1; i < argc; i++)
			ScalarConverter::convert(argv[i]);
}
