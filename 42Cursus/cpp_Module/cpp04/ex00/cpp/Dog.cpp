#include "../hpp/Dog.hpp"


Dog::Dog():Animal("Dog")
{
	cout<<"[Dog] "<<"Default constructor called."<<endl;
}
Dog::Dog(const Dog &Dog):Animal(Dog.type)
{
	cout<<"[Dog] "<<"Copy constructor called."<<endl;
}
Dog &Dog::operator =(const Dog &Dog)
{
	cout<<"[Dog] "<<"Copy assignment operator called."<<endl;
	type = Dog.type;
	return (*this);
}
Dog::~Dog()
{
	cout<<"[Dog] "<<"Destructor called."<<endl;
}

void Dog::makeSound() const
{
	Animal::makeSound("Wal! Wal!");
}
