#include "../hpp/Dog.hpp"


Dog::Dog():Animal("Dog")
{
	cout<<"[Dog] "<<"Default constructor called."<<endl;
}
Dog::Dog(const Dog &dog):Animal(dog.type)
{
	cout<<"[Dog] "<<"Copy constructor called."<<endl;
}
Dog &Dog::operator =(const Dog &dog)
{
	cout<<"[Dog] "<<"Copy assignment operator called."<<endl;
	type = dog.type;
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
