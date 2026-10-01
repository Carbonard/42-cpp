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

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signRequiredGrade;
	const int			_executeRequiredGrade;

protected:
	virtual void executeAction() = 0;

public:
	AForm();
	AForm(const std::string &name, const int signRequirement, const int executeRequirement);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();


	std::string getName() const;
	int getIsSigned() const;
	int getSignRequiredGrade() const;
	int getExecuteRequiredGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor);


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

	class NotSignedException: public std::exception
	{
	private:
		std::string	_msg;

	public:
		NotSignedException();
		NotSignedException(std::string const &msg);
		~NotSignedException() throw();

		const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &os, const AForm &form);

#endif
