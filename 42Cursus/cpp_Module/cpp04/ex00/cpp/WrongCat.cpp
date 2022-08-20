#include "../hpp/WrongCat.hpp"


WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	cout<<"[WrongCat] "<<"Default constructor called."<<endl;
}
WrongCat::WrongCat(const WrongCat &WrongCat):WrongAnimal(WrongCat.type)
{
	cout<<"[WrongCat] "<<"Copy constructor called."<<endl;
}
WrongCat &WrongCat::operator =(const WrongCat &WrongCat)
{
	cout<<"[WrongCat] "<<"Copy assignment operator called."<<endl;
	type = WrongCat.type;
	return (*this);
}
WrongCat::~WrongCat()
{
	cout<<"[WrongCat] "<<"Destructor called."<<endl;
}

void WrongCat::makeSound() const
{
	WrongAnimal::makeSound("MU YA HO~!");
}