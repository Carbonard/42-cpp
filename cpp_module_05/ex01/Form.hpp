#ifndef FORM_HPP
#define FORM_HPP

#ifndef B_MIN_GRADE
	#define B_MIN_GRADE 150
#endif
#ifndef B_MAX_GRADE
	#define B_MAX_GRADE 1
#endif

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signRequiredGrade;
	const int			_executeRequiredGrade;

public:
	Form();
	Form(const std::string &name, const int signRequirement, const int executeRequirement);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();


	std::string getName() const;
	int getIsSigned() const;
	int getSignRequiredGrade() const;
	int getExecuteRequiredGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);


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

std::ostream &operator <<(std::ostream &os, const Form &form);

#endif
