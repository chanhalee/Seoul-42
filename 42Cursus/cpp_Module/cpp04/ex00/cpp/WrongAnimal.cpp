#include "../hpp/WrongAnimal.hpp"


WrongAnimal::WrongAnimal():type("NoType")
{
	cout<<"[WrongAnimal] "<<"Default constructor called."<<endl;
}
WrongAnimal::WrongAnimal(string type):type(type)
{
	cout<<"[WrongAnimal] "<<"String constructor called."<<endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal):type(WrongAnimal.type)
{
	cout<<"[WrongAnimal] "<<"Copy constructor called."<<endl;
}
WrongAnimal &WrongAnimal::operator =(const WrongAnimal &WrongAnimal)
{
	cout<<"[WrongAnimal] "<<"Copy assignment operator called."<<endl;
	type = WrongAnimal.type;
	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	cout<<"[WrongAnimal] "<<"Destructor called."<<endl;
}

void WrongAnimal::makeSound() const
{
	cout<<type<<": ..."<<endl;
}

void WrongAnimal::makeSound(string sound) const
{
	cout<<type<<": "<<sound<<endl;
}

string WrongAnimal::getType() const
{
	return type;
}