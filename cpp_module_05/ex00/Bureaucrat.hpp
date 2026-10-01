#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define B_MIN_GRADE 150
#define B_MAX_GRADE 1

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();


	class GradeTooHighException: public std::exception
	{
	private:
		std::string	_msg;

	public:
		GradeTooHighException();
		GradeTooHighException(std::string const &msg);
		~GradeTooHighException() throw();

		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	private:
		std::string	_msg;

	public:
		GradeTooLowException();
		GradeTooLowException(std::string const &msg);
		~GradeTooLowException() throw();

		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
