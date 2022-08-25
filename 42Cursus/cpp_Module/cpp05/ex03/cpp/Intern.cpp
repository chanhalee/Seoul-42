#include "../hpp/Intern.hpp"


Intern::Intern()
{
	cout<<"[Intern] "<<"Default constructor called."<<endl;
}
Intern::Intern(const Intern &intern)
{
	cout<<"[Intern] "<<"Copy constructor called."<<endl;
	intern.doNothing();
}
Intern &Intern::operator=(const Intern &intern)
{
	cout<<"[Intern] "<<"Copy assignment operator called."<<endl;
	intern.doNothing();
	return (*this);
}
Intern::~Intern()
{
	cout<<"[Intern] "<<"Destructor called."<<endl;
}
Form *Intern::makePForm(const string &target) const
{
	return (new PresidentialPardonForm(target));
}
Form *Intern::makeRForm(const string &target) const
{
	return (new RobotomyRequestForm(target));
}
Form *Intern::makeSForm(const string &target) const
{
	return (new ShrubberyCreationForm(target));
}
Form *Intern::makeForm(const string &name, const string &target) const
{
	int index;
	string nameArr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form *(Intern:: *funArr[3])(const string &target) const = {&Intern::makeRForm, &Intern::makePForm, &Intern::makeSForm};

	index = -1;
	while(++index < 3)
	{
		if (name == nameArr[index])
			return (this->*funArr[index])(target);
	}
	cout<<"There is no such Form as "<<name<<endl;
	return (NULL);
}

void Intern::doNothing(void) const
{
	return;
}