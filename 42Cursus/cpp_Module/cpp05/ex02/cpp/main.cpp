#include "../hpp/Bureaucrat.hpp"
#include "../hpp/PresidentialPardonForm.hpp"
#include "../hpp/RobotomyRequestForm.hpp"
#include "../hpp/ShrubberyCreationForm.hpp"
#include "../hpp/Form.hpp"

int main(void)
{
	cout<<"\n\n==================================\n\n";
	try
	{
		//Form f1;
		Bureaucrat b1s("B1s", 145);
		Bureaucrat b1e("B1e", 137);
		Bureaucrat b2s("B2s", 72);
		Bureaucrat b2e("B2e", 45);
		Bureaucrat b3s("B3s", 25);
		Bureaucrat b3e("B3e", 5);

		cout<<b1s;
		cout<<b1e;
		cout<<b2s;
		cout<<b2e;
		cout<<b3s;
		cout<<b3e;
		cout<<endl;
		ShrubberyCreationForm homeS("HomeS");
		RobotomyRequestForm homeR("HomeR");
		PresidentialPardonForm homeP("HomeP");
		cout<<endl;
		homeS.execute(b1e);
		homeS.beSigned(b1s);
		homeS.execute(b1e);
		b1e.demote();
		//homeS.execute(b1e);
		//homeR.beSigned(b1s);
		cout<<endl;
		homeR.beSigned(b2s);
		homeR.execute(b2e);
		cout<<endl;
		homeP.beSigned(b3s);
		homeP.execute(b3e);
		cout<<endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}