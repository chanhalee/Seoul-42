#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}


	{
		Animal* array[10];
		for (int i = 0; i < 5; i++)
			array[i] = new Dog();
		for (int i = 5; i < 10; i++)
			array[i] = new Cat();

		for (int i = 0; i < 10; i++)
			array[i]->makeSound();

		for (int i = 0; i < 10; i++)
			delete array[i];
	}


	{
		Dog* dog1 = new Dog();
		Dog* dog2 = new Dog();

		dog1->setBrain("dog1");

		cout << "\n\ndog1\n" << endl;
		dog1->printBrain();
		cout << "\n\ndog2\n" << endl;
		dog2->printBrain();

		*dog2 = *dog1;
		cout << "\n\ndog1\n" << endl;
		dog1->printBrain();
		cout << "\n\ndog2\n" << endl;
		dog2->printBrain();

		delete dog1;
		delete dog2;
	}
	//while (1);
	return 0;
}