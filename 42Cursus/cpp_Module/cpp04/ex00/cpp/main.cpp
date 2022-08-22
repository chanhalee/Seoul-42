#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		cout<<animal->getType()<<endl;
		cout<<dog->getType()<<endl;
		cout<<cat->getType()<<endl;
		animal->makeSound();
		dog->makeSound();
		cat->makeSound();
		delete animal;
		delete dog;
		delete cat;
	}

	{
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		cout<<wrongAnimal->getType()<<endl;
		cout<<wrongCat->getType()<<endl;

		wrongAnimal->makeSound();
		wrongCat->makeSound();

		delete wrongAnimal;
		delete wrongCat;
	}
	
	return 0;
}