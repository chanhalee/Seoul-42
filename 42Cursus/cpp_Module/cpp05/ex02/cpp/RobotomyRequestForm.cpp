#include "../hpp/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("NoName")
{
	cout<<"[RobotomyRequestForm] "<<"Default constructor called."<<endl;
}
RobotomyRequestForm::RobotomyRequestForm(const string target):Form("RobotomyRequestForm", 72, 45), target(target)
{
	cout<<"[RobotomyRequestForm] "<<"Arguments constructor called."<<endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm):Form(robotomyRequestForm), target(robotomyRequestForm.target)
{
	cout<<"[RobotomyRequestForm] "<<"Arguments constructor called."<<endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
	cout<<"[RobotomyRequestForm] "<<"Copy assignment operator called."<<endl;
	*(Form *)this = robotomyRequestForm;
	target = robotomyRequestForm.target;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	cout<<"[RobotomyRequestForm] "<<"Destructor called."<<endl;
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getAuthorized())
	{
		executor.executeForm(*this);
		if (this->getExecuteGrade() >= executor.getGrade())
		{
			cout<<"some DRILLING NOISE!"<<endl;
			std::srand(std::time(NULL));
			if (std::rand() % 100 >= 50)
				cout<<target<<" has been robotomized successfully!"<<endl;
			else
				cout<<target<<" has been failed to robotomize"<<endl;
		}
		else
			throw Form::GradeTooLowException();
	}
	else
		cout<<"Can't Execute! "<<this->getName()<<" is Not Authorized!"<<endl;
}