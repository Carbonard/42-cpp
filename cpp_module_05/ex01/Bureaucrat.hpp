#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#ifndef B_MIN_GRADE
	#define B_MIN_GRADE 150
#endif
#ifndef B_MAX_GRADE
	#define B_MAX_GRADE 1
#endif

#include <string>
#include <iostream>

class Form;

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
	void	signForm(Form &form);


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
