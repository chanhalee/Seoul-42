#include "../hpp/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5), target("NoName")
{
	cout<<"[PresidentialPardonForm] "<<"Default constructor called."<<endl;
}
PresidentialPardonForm::PresidentialPardonForm(const string target):Form("PresidentialPardonForm", 25, 5), target(target)
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
	*(Form *)this = presidentialPardonForm;
	target = presidentialPardonForm.target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	cout<<"[PresidentialPardonForm] "<<"Destructor called."<<endl;
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getAuthorized())
	{
		executor.executeForm(*this);
		if (this->getExecuteGrade() >=  executor.getGrade())
		{
			cout<<target<<" has been pardoned by Zaphod Beeblebrox"<<endl;
		}
		else
			throw Form::GradeTooLowException();
	}
	else
		cout<<"Can't Execute! "<<this->getName()<<" is Not Authorized!"<<endl;
}