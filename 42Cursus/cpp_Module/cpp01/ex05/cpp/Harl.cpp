#include "../hpp/Harl.hpp"

void Harl::debug(void)
{
	cout<<"\n\n=====DEBUG====\n";
	cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	cout<<"\n"<<endl;
}

void Harl::info(void)
{
	cout<<"\n\n=====INFO====\n";
	cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
	cout<<"\n"<<endl;
}

void Harl::warning(void)
{
	cout<<"\n\n=====WARNING====\n";
	cout<<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
	cout<<"\n"<<endl;
}

void Harl::error(void)
{
	cout<<"\n\n=====ERROR====\n";
	cout<<"This is unacceptable! I want to speak to the manager now.\n";
	cout<<"\n"<<endl;
}

void Harl::complain(string level)
{
	int	index;

	void(Harl:: *fun[4])()  = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string instruction[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	index = -1;
	while(++index < 4)
	{
		if (level == instruction[index])
		{
			(this->*fun[index])();
			return ;
		}
	}
	cout<<"wrong instruction"<<endl;
}