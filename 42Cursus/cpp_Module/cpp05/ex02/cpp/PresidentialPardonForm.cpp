#include "../hpp/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 145, 137), target("NoName")
{
	cout<<"[PresidentialPardonForm] "<<"Default constructor called."<<endl;
}
PresidentialPardonForm::PresidentialPardonForm(const string target):Form("PresidentialPardonForm", 145, 137), target(target)
{
	cout<<"[PresidentialPardonForm] "<<"Arguments constructor called."<<endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm):Form(presidentialPardonForm), target(presidentialPardonForm.target)
{
	cout<<"[PresidentialPardonForm] "<<"Arguments constructor called."<<endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	cout<<"[PresidentialPardonForm] "<<"Copy assignment operator called."<<endl;
	*this = presidentialPardonForm;
	target = presidentialPardonForm.target;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	cout<<"[PresidentialPardonForm] "<<"Destructor called."<<endl;
}
int PresidentialPardonForm::execute(Bureaucrat &executor)
{
	if (!this->getAuthorized())
	{
		executor.executeForm(*this);
		if (this->getExecuteGrade() < executor.getGrade())
		{
			;
		}
		else
			throw Form::GradeTooLowException();
	}
	else
		cout<<"Can't Execute! "<<this->getName()<<" is Not Authorized!";
}