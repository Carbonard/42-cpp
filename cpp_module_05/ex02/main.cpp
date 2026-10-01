#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	ShrubberyCreationForm f_1("target_1");
	RobotomyRequestForm f_2("target_2");
	PresidentialPardonForm f_3("target_3");

	Bureaucrat highB("The Boss", B_MAX_GRADE);
	Bureaucrat midB("MidLevelEmployee", 70);
	Bureaucrat lowB("LowLevelEmployee", B_MIN_GRADE);

	std::cout << std::endl;
	lowB.executeForm(f_1);
	std::cout << std::endl;
	midB.executeForm(f_1);
	std::cout << std::endl;
	lowB.signForm(f_1);
	std::cout << std::endl;
	midB.signForm(f_1);
	std::cout << std::endl;
	lowB.executeForm(f_1);
	std::cout << std::endl;
	midB.executeForm(f_1);
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
	lowB.executeForm(f_3);
	std::cout << std::endl;
	midB.executeForm(f_3);
	std::cout << std::endl;
	highB.executeForm(f_3);
	std::cout << std::endl;
	lowB.signForm(f_3);
	std::cout << std::endl;
	midB.signForm(f_3);
	std::cout << std::endl;
	highB.signForm(f_3);
	std::cout << std::endl;
	lowB.executeForm(f_3);
	std::cout << std::endl;
	midB.executeForm(f_3);
	std::cout << std::endl;
	highB.executeForm(f_3);
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
	lowB.executeForm(f_2);
	std::cout << std::endl;
	midB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	lowB.signForm(f_2);
	std::cout << std::endl;
	midB.signForm(f_2);
	std::cout << std::endl;
	lowB.executeForm(f_2);
	std::cout << std::endl;
	midB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;
	highB.executeForm(f_2);
	std::cout << std::endl;

}

/*
	DUDAS:
	- igualar forms (originales y ahora para llamar a aquella)
	- Default constructors?
*/