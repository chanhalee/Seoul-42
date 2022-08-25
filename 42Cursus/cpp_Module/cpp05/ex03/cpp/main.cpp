#include "../hpp/Bureaucrat.hpp"
#include "../hpp/PresidentialPardonForm.hpp"
#include "../hpp/RobotomyRequestForm.hpp"
#include "../hpp/ShrubberyCreationForm.hpp"
#include "../hpp/Form.hpp"
#include "../hpp/Intern.hpp"

int main(void)
{
	cout<<"\n\n==================================\n\n";
	try
	{
		Intern  someRandomIntern;
		Bureaucrat bureaucrat("B1", 1);
		Form*   rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf == NULL)
		{
			cout<<"NULL ptr returned."<<endl;
		}
		else
		{
			rrf->beSigned(bureaucrat);
			rrf->execute(bureaucrat);
			delete rrf;
		}
		cout<<"\n\n==================================\n\n";
		rrf = someRandomIntern.makeForm("bla bla", "Bender");
		if (rrf == NULL)
		{
			cout<<"NULL ptr returned."<<endl;
		}
		else
		{
			rrf->beSigned(bureaucrat);
			rrf->execute(bureaucrat);
			delete rrf;
		}
		cout<<"\n\n==================================\n\n";
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf == NULL)
		{
			cout<<"NULL ptr returned."<<endl;
		}
		else
		{
			rrf->beSigned(bureaucrat);
			rrf->execute(bureaucrat);
			delete rrf;
		}
		cout<<"\n\n==================================\n\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}