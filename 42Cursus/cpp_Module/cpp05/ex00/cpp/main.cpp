#include "../hpp/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1;
		cout<<b1;
		Bureaucrat b2("B2", 148);
		cout<<b2;
		Bureaucrat b3("B3", 1);
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
	return (0);
}