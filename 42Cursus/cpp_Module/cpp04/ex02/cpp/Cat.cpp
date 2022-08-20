#include "../hpp/Cat.hpp"


Cat::Cat():Animal("Cat")
{
	cout<<"[Cat] "<<"Default constructor called."<<endl;
	brain = new Brain();
}
Cat::Cat(const Cat &cat):Animal(cat.type)
{
	cout<<"[Cat] "<<"Copy constructor called."<<endl;
	brain = new Brain(*cat.brain);
}
Cat &Cat::operator =(const Cat &cat)
{
	cout<<"[Cat] "<<"Copy assignment operator called."<<endl;
	type = cat.type;
	(*brain) = *(cat.brain);
	return (*this);
}
Cat::~Cat()
{
	cout<<"[Cat] "<<"Destructor called."<<endl;
	delete brain;
}

void Cat::makeSound() const
{
	Animal::makeSound("Meow~");
}

void Cat::setBrain(const string str)
{
	brain->setBrain(str);
}
void Cat::printBrain(void)
{
	brain->printBrain();
}