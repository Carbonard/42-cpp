#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat foo("Jules", 42);

	std::cout << foo << std::endl;
	foo.incrementGrade();
	std::cout << foo << std::endl;
	foo.decrementGrade();
	std::cout << foo << std::endl;

	try
	{
		Bureaucrat bar("Lola", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "cathed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bar("Lola", 200);
	}
	catch (std::exception &e)
	{
		std::cout << "cathed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bar("Lola", 1);
		bar.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "cathed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bar("Lola", B_MIN_GRADE);
		bar.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "cathed: " << e.what() << std::endl;
	}
}