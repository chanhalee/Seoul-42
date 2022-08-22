#include "../hpp/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("NoName"), grade(150)
{
	cout<<"[Bureaucrat] "<<"Default constructor called."<<endl;
}
Bureaucrat::Bureaucrat(string name, int grade):name(name), grade(grade)
{
	cout<<"[Bureaucrat] "<<"Arguments constructor called."<<endl;
	if (grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):name(bureaucrat.name), grade(bureaucrat.grade)
{
	cout<<"[Bureaucrat] "<<"Copy constructor called."<<endl;
	if (grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}
Bureaucrat &Bureaucrat::operator =(const Bureaucrat &bureaucrat)
{
	cout<<"[Bureaucrat] "<<"Copy assignment operator called."<<endl;
	if (grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	const_cast<string &>(name) = bureaucrat.name;
	grade = bureaucrat.grade;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	cout<<"[Bureaucrat] "<<"Destructor called."<<endl;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}
string Bureaucrat::getName(void) const
{
	return name;
}
int Bureaucrat::getGrade(void) const
{
	return grade;
}
void Bureaucrat::promote()
{
	if (grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		--grade;
		cout<<name<<" promoted [" <<grade<<"]"<<endl;
	}
}
void Bureaucrat::demote()
{
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		++grade;
		cout<<name<<" demoted [" <<grade<<"]"<<endl;
	}
}

ostream &operator <<(ostream &os, const Bureaucrat &bureaucrat)
{
	os<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<endl;
	return (os);
}
void Bureaucrat::signForm(const Form &form) const
{
	if (form.getAuthorized())
		cout<<name<<" couldn't sign "<<form.getName()<<" because "<<"It's already signed"<<endl;
	else if (grade > form.getSignGrade())
		cout<<name<<" couldn't sign "<<form.getName()<<" because "<<"bureaucrat grade is too LOW"<<endl;
	else
		cout<<name<<" signed "<<form.getName()<<endl;
}

void Bureaucrat::executeForm(Form const &form)
{
	if (grade > form.getExecuteGrade())
		cout<<name<<" couldn't execute "<<form.getName()<<" because "<<"bureaucrat grade is too LOW"<<endl;
	else
		cout<<name<<" executed "<<form.getName()<<endl;
}