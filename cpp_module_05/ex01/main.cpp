#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
{
	Form importantForm("Maximum-importance", B_MAX_GRADE, B_MAX_GRADE);
	Form unimportantForm("Minimum-importance", B_MIN_GRADE, B_MIN_GRADE);
	Bureaucrat boss("The Boss", B_MAX_GRADE);

	std::cout << unimportantForm << std::endl;
	boss.signForm(unimportantForm);
	std::cout << unimportantForm << std::endl;
	std::cout << importantForm << std::endl;
	boss.signForm(importantForm);
	std::cout << importantForm << std::endl;
}
{
	Form importantForm("Maximum-importance", B_MAX_GRADE, B_MAX_GRADE);
	Form unimportantForm("Minimum-importance", B_MIN_GRADE, B_MIN_GRADE);
	Bureaucrat employee("Unimportant employee", B_MIN_GRADE);

	std::cout << unimportantForm << std::endl;
	employee.signForm(unimportantForm);
	std::cout << unimportantForm << std::endl;
	std::cout << importantForm << std::endl;
	employee.signForm(importantForm);
	std::cout << importantForm << std::endl;
}
	try
	{
		Form impossibleForm("This should not exist", 200, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form impossibleForm("This should not exist", 100, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form impossibleForm("This should not exist", 0, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form impossibleForm("This should not exist", 100, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}