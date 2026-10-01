#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[34m" << message << std::endl << "\e[0m";
}

Form::Form():
_name("Useless form"),
_isSigned(false),
_signRequiredGrade(B_MIN_GRADE),
_executeRequiredGrade(B_MIN_GRADE)
{
	print_debug("Form default constructor");
}

Form::Form(const std::string &name, const int signRequirement, const int executeRequirement):
_name(name),
_isSigned(false),
_signRequiredGrade(signRequirement),
_executeRequiredGrade(executeRequirement)
{
	print_debug("Form data constructor");
	if (signRequirement < B_MAX_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooHighException("The required range to sign is too high");
	}
	if (signRequirement > B_MIN_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooLowException("The required range to sign is too low");
	}
	if (executeRequirement < B_MAX_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooHighException("The required range to execute is too high");
	}
	if (executeRequirement > B_MIN_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooLowException("The required range to execute is too low");
	}
}

Form::Form(const Form &other):
_name(other._name),
_isSigned(false),
_signRequiredGrade(other._signRequiredGrade),
_executeRequiredGrade(other._executeRequiredGrade)
{
	print_debug("Form copy constructor");
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	print_debug("Form assignment operator");
	this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	print_debug("Form destructor");
}

std::ostream &operator <<(std::ostream &os, const Form &form)
{
	os
	<< form.getName() << " form "
	<< "(which requires a grade " << form.getSignRequiredGrade() << " to be signed"
	<< " and " << form.getExecuteRequiredGrade() << " to be executed"
	<< ", and is " << (form.getIsSigned() ? "" : "not ") << "signed)";
	return os;
}

// Form methods

std::string Form::getName() const
{
	return _name;
}

int Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignRequiredGrade() const
{
	return _signRequiredGrade;
}

int Form::getExecuteRequiredGrade() const
{
	return _executeRequiredGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signRequiredGrade)
		throw GradeTooLowException("the bureaucrat grade is too low");
	this->_isSigned = true;
}

// Exceptions

Form::GradeTooHighException::GradeTooHighException()
: _msg("Form required grade too high")
{}

Form::GradeTooHighException::GradeTooHighException(const std::string &message)
: _msg(message)
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *Form::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException()
: _msg("Form required grade too low")
{}

Form::GradeTooLowException::GradeTooLowException(const std::string &message)
: _msg(message)
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *Form::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}
