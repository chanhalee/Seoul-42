#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Form
{
private:
	const string name;
	bool authorized;
	const int signGrade;
	const int executeGrade;
public:
	Form();
	Form(const Form &form);
	Form(const string name, int signGrade, int executeGrade);
	Form &operator=(const Form &form);
	~Form();
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	string getName(void) const;
	bool getAuthorized(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
};
ostream &operator <<(ostream &os, const Form &form);

#endif