#include "Bureaucrat.hpp"
#include <iostream>

static void print_debug(std::string message)
{
	std::cout << "\e[33m" << message << std::endl << "\e[0m";
}

Bureaucrat::Bureaucrat()
: _name("Nobody"), _grade(B_MIN_GRADE)
{
	print_debug("Bureaucrat default constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name)
{
	print_debug("Bureaucrat copy constructor");
	*this = other;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
: _name(name)
{
	print_debug("Bureaucrat name/grade constructor");
	if (grade < B_MAX_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooHighException();
	}
	if (grade > B_MIN_GRADE)
	{
		print_debug("Aborting constructor");
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	print_debug("Bureaucrat assignment operator");
	this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	print_debug("Bureaucrat destructor");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

// Bureaucrat methods:

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == B_MAX_GRADE)
		throw GradeTooHighException("Cannot increment bureaucrat grade");
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == B_MIN_GRADE)
		throw GradeTooLowException("Cannot decrement bureaucrat grade");
	this->_grade++;
}

// Exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException()
: _msg("Bureaucrat grade too high")
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message)
: _msg(message)
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
: _msg("Bureaucrat grade too low")
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message)
: _msg(message)
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}