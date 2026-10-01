#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[34m" << message << std::endl << "\e[0m";
}

AForm::AForm():
_name("Useless form"),
_isSigned(false),
_signRequiredGrade(B_MIN_GRADE),
_executeRequiredGrade(B_MIN_GRADE)
{
	print_debug("AForm default constructor");
}

AForm::AForm(const std::string &name, const int signRequirement, const int executeRequirement):
_name(name),
_isSigned(false),
_signRequiredGrade(signRequirement),
_executeRequiredGrade(executeRequirement)
{
	print_debug("AForm data constructor");
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

AForm::AForm(const AForm &other):
_name(other._name),
_isSigned(false),
_signRequiredGrade(other._signRequiredGrade),
_executeRequiredGrade(other._executeRequiredGrade)
{
	print_debug("AForm copy constructor");
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	print_debug("AForm assignment operator");
	this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	print_debug("AForm destructor");
}

std::ostream &operator <<(std::ostream &os, const AForm &form)
{
	os
	<< form.getName() << " form "
	<< "(which requires a grade " << form.getSignRequiredGrade() << " to be signed"
	<< " and " << form.getExecuteRequiredGrade() << " to be executed"
	<< ", and is " << (form.getIsSigned() ? "" : "not ") << "signed)";
	return os;
}

// AForm methods

std::string AForm::getName() const
{
	return _name;
}

int AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignRequiredGrade() const
{
	return _signRequiredGrade;
}

int AForm::getExecuteRequiredGrade() const
{
	return _executeRequiredGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signRequiredGrade)
		throw GradeTooLowException("the bureaucrat grade is too low");
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor)
{
	if (executor.getGrade() > this->_executeRequiredGrade)
		throw GradeTooLowException("the bureaucrat grade is too low");
	if (!_isSigned)
		throw NotSignedException("the form is not signed");
	this->executeAction();
}

// Exceptions

AForm::GradeTooHighException::GradeTooHighException()
: _msg("Form required grade too high")
{}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message)
: _msg(message)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *AForm::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException()
: _msg("Form required grade too low")
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message)
: _msg(message)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *AForm::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}

AForm::NotSignedException::NotSignedException()
: _msg("Form is not signed")
{}

AForm::NotSignedException::NotSignedException(const std::string &message)
: _msg(message)
{}

AForm::NotSignedException::~NotSignedException() throw()
{}

const char *AForm::NotSignedException::what() const throw()
{
	return _msg.c_str();
}
