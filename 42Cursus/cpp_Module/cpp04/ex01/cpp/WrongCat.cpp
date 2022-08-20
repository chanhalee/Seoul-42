#include "../hpp/WrongCat.hpp"


WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	cout<<"[WrongCat] "<<"Default constructor called."<<endl;
}
WrongCat::WrongCat(const WrongCat &wrongCat):WrongAnimal(wrongCat.type)
{
	cout<<"[WrongCat] "<<"Copy constructor called."<<endl;
}
WrongCat &WrongCat::operator =(const WrongCat &wrongCat)
{
	cout<<"[WrongCat] "<<"Copy assignment operator called."<<endl;
	type = wrongCat.type;
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