#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		const Animal* i = new Cat();
		//const Animal* j = new Animal();

		i->makeSound();
		delete i;
		//delete j;
	}
	//while (1);
	return (0);
}