#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5),
_target("Anyone")
{
	print_debug("PresidentialPardonForm default constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{
	print_debug("PresidentialPardonForm target constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
AForm("PresidentialPardonForm", 25, 5),
_target(other._target)
{
	print_debug("PresidentialPardonForm copy constructor");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	print_debug("PresidentialPardonForm assignment operator");
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	print_debug("PresidentialPardonForm destructor");
}

void PresidentialPardonForm::executeAction()
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
