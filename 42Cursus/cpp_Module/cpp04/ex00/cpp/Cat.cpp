#include "../hpp/Cat.hpp"


Cat::Cat():Animal("Cat")
{
	cout<<"[Cat] "<<"Default constructor called."<<endl;
}
Cat::Cat(const Cat &Cat):Animal(Cat.type)
{
	cout<<"[Cat] "<<"Copy constructor called."<<endl;
}
Cat &Cat::operator =(const Cat &Cat)
{
	cout<<"[Cat] "<<"Copy assignment operator called."<<endl;
	type = Cat.type;
	return (*this);
}
Cat::~Cat()
{
	cout<<"[Cat] "<<"Destructor called."<<endl;
}

void Cat::makeSound() const
{
	Animal::makeSound("Meow~");
}