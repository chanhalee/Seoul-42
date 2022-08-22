#include "../hpp/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1;
		cout<<b1;
		Bureaucrat b2("B2", 148);
		cout<<b2;
		Bureaucrat b3("B3", 3);
		cout<<b3;
		b2.promote();
		b2.demote();
		b2.demote();
		b2.demote();
		//b2.demote();
		b3.promote();
		b3.promote();
		//b3.promote();
		//Bureaucrat b4("B4", 151);
		//Bureaucrat b5("B5", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout<<"\n\n==================================\n\n";
	try
	{
		Form f1;
		Bureaucrat b2("B2", 148);
		Bureaucrat b3("B3", 3);
		Form f2("F2", 148, 149);
		Form  f3("F3", 3, 5);
		cout<<f1;
		cout<<f2;
		cout<<f3;
		//f2.beSigned(b2);
		//f2.beSigned(b3);
		b2.demote();
		f2.beSigned(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}