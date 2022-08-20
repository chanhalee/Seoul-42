#include "../hpp/Animal.hpp"


Animal::Animal():type("NoType")
{
	cout<<"[Animal] "<<"Default constructor called."<<endl;
}
Animal::Animal(string type):type(type)
{
	cout<<"[Animal] "<<"String constructor called."<<endl;
}
Animal::Animal(const Animal &animal):type(animal.type)
{
	cout<<"[Animal] "<<"Copy constructor called."<<endl;
}
Animal &Animal::operator =(const Animal &animal)
{
	cout<<"[Animal] "<<"Copy assignment operator called."<<endl;
	type = animal.type;
	return (*this);
}
Animal::~Animal()
{
	cout<<"[Animal] "<<"Destructor called."<<endl;
}

void Animal::makeSound() const
{
	cout<<type<<": ..."<<endl;
}

void Animal::makeSound(string sound) const
{
	cout<<type<<": "<<sound<<endl;
}

string Animal::getType() const
{
	return type;
}