#include "../hpp/Dog.hpp"


Dog::Dog():Animal("Dog")
{
	cout<<"[Dog] "<<"Default constructor called."<<endl;
	brain = new Brain();
}
Dog::Dog(const Dog &dog):Animal(dog.type)
{
	cout<<"[Dog] "<<"Copy constructor called."<<endl;
	brain = new Brain(*dog.brain);
}
Dog &Dog::operator =(const Dog &dog)
{
	cout<<"[Dog] "<<"Copy assignment operator called."<<endl;
	type = dog.type;
	(*brain) = *(dog.brain);
	return (*this);
}
Dog::~Dog()
{
	cout<<"[Dog] "<<"Destructor called."<<endl;
	delete brain;
}

void Dog::makeSound() const
{
	Animal::makeSound("Wal! Wal!");
}

void Dog::setBrain(const string str)
{
	brain->setBrain(str);
}
void Dog::printBrain(void)
{
	brain->printBrain();
}