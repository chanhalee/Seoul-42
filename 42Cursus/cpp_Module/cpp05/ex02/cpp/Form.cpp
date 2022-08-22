#include "../hpp/Form.hpp"



Form::Form():name("NoName"), authorized(false), signGrade(1), executeGrade(1)
{
	cout<<"[Form] "<<"Default constructor called."<<endl;
}
Form::Form(const Form &form):name(form.name), authorized(form.authorized), signGrade(form.signGrade), executeGrade(form.executeGrade)
{
	cout<<"[Form] "<<"Copy constructor called."<<endl;
	if (signGrade < 1|| executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const string name, int signGrade, int executeGrade):name(name), authorized(false), signGrade(signGrade), executeGrade(executeGrade)
{
	cout<<"[Form] "<<"Arguments constructor called."<<endl;
	if (signGrade < 1|| executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}
Form &Form::operator=(const Form &form)
{
	cout<<"[Form] "<<"Copy assignment operator called."<<endl;
	const_cast<string &>(name) = form.name;
	const_cast<int &>(signGrade) = form.signGrade;
	const_cast<int &>(executeGrade) = form.executeGrade;
	authorized = form.authorized;
	if (signGrade < 1|| executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	return (*this);
}
Form::~Form()
{
	cout<<"[Form] "<<"Destructor called."<<endl;
}
string Form::getName(void) const
{
	return (name);
}
bool Form::getAuthorized(void) const
{
	return authorized;
}
int Form::getSignGrade(void) const
{
	return signGrade;
}
int Form::getExecuteGrade(void) const
{
	return executeGrade;
}
bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(*this);
	if (! authorized)
	{
		if (bureaucrat.getGrade() > signGrade)
		{
			throw Form::GradeTooLowException();
		}
		else
			authorized = true;
	}
	return authorized;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

ostream &operator <<(ostream &os, const Form &form)
{
	os<<"\n*Form*\n name: "<<form.getName()<<"\n authorized: ";
	if(form.getAuthorized())
		os<<"TRUE\n";
	else
		os<<"FALSE\n";
	os<<" signGrade: "<<form.getSignGrade()<<"\n executeGrade: "<<form.getExecuteGrade()<<endl;
	return (os);
}