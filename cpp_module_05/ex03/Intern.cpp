#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Intern::Intern()
{
	print_debug("Intern default constructor");
}

Intern::Intern(const Intern &other)
{
	print_debug("Intern copy constructor");
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	print_debug("Intern assignment operator");
	(void) other;
	return *this;
}

Intern::~Intern()
{
	print_debug("Intern destructor");
}

AForm *newShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *newRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *newPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

typedef struct s_formGenerator
{
	std::string name;
	AForm *(*createForm)(const std::string &target);
}	t_formGenerator;

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	t_formGenerator	generator[] = {
		{"shrubbery creation", newShrubberyCreationForm},
		{"robotomy request", newRobotomyRequestForm},
		{"presidential pardon", newPresidentialPardonForm},
		{"", NULL}
	};
	AForm *form;

	for (int i = 0; generator[i].name.length(); i++)
	{
		if (generator[i].name == formName)
		{
			form = generator[i].createForm(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
		}
	}
	std::cout << "Form '" << formName << "' does not exist" << std::endl;
	return (NULL);
}
