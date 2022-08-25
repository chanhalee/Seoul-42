#include "../hpp/ShrubberyCreationForm.hpp"
#include "../hpp/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("NoName")
{
	cout<<"[ShrubberyCreationForm] "<<"Default constructor called."<<endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const string target):Form("ShrubberyCreationForm", 145, 137), target(target)
{
	cout<<"[ShrubberyCreationForm] "<<"Arguments constructor called."<<endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm):Form(shrubberyCreationForm), target(shrubberyCreationForm.target)
{
	cout<<"[ShrubberyCreationForm] "<<"Arguments constructor called."<<endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	cout<<"[ShrubberyCreationForm] "<<"Copy assignment operator called."<<endl;
	*(Form *)this = shrubberyCreationForm;
	target = shrubberyCreationForm.target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout<<"[ShrubberyCreationForm] "<<"Destructor called."<<endl;
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream fout;
	string outFileName = target;
	if (this->getAuthorized())
	{
		executor.executeForm(*this);
		if (this->getExecuteGrade() >= executor.getGrade())
		{

			fout.open(outFileName.append("_shrubbery"), std::ios::trunc);
			if (!fout.is_open())
			{
				std::cout<<"[ShrubberyCreationForm] "<<"output file open error!"<<std::endl;
				return ;
			}
			fout<<"                             \n";
			fout<<"              *              \n";
			fout<<"             ***             \n";
			fout<<"            *****            \n";
			fout<<"           *******           \n";
			fout<<"          *********          \n";
			fout<<"         ***********         \n";
			fout<<"             ***             \n";
			fout<<"             ***             \n";
			fout<<"            *****            \n";
			fout<<"*****************************\n";
			fout<<"*****************************";
			fout.close();
		}
		else
			throw Form::GradeTooLowException();
	}
	else
		cout<<"Can't Execute! "<<this->getName()<<" is Not Authorized!"<<endl;
	return ;
}