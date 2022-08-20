#include "../hpp/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("NoName"), grade(150)
{
	cout<<"[Bureaucrat] "<<"Default constructor called."<<endl;
}
Bureaucrat::Bureaucrat(string name, int grade):name(name), grade(grade)
{
	cout<<"[Bureaucrat] "<<"String constructor called."<<endl;
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):name(bureaucrat.name), grade(bureaucrat.grade)
{
	cout<<"[Bureaucrat] "<<"Copy constructor called."<<endl;
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
}
Bureaucrat &Bureaucrat::operator =(const Bureaucrat &bureaucrat)
{
	cout<<"[Bureaucrat] "<<"Copy assignment operator called."<<endl;
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	if (grade >= 150)
	{
		throw GradeTooLowException();
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
	return "GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
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
		throw GradeTooHighException();
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
		throw GradeTooLowException();
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