#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45),
_target("Anyone")
{
	print_debug("RobotomyRequestForm default constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
	print_debug("RobotomyRequestForm target constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
AForm("RobotomyRequestForm", 72, 45),
_target(other._target)
{
	print_debug("RobotomyRequestForm copy constructor");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	print_debug("RobotomyRequestForm assignment operator");
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	print_debug("RobotomyRequestForm destructor");
}

void RobotomyRequestForm::executeAction()
{
	std::cout << "\aMaking some drilling noises...\a\a\a\a\a\a\a" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization has failed" << std::endl;
}
