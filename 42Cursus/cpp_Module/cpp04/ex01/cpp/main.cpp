#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		std::cout << "========== Default ==========" << std::endl;
	
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j; //should not create a leak
		delete i;
	}


	{
		std::cout << "\n\n========== Animal array ==========" << std::endl;

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
		std::cout << "\n\n========== Brain Deep Copy ==========" << std::endl;
		Dog* dog1 = new Dog();
		Dog* dog2 = new Dog();

		dog1->setBrain("I'm cute dog 1 🐶!!");

		std::cout << "\n********** Dog 1's brain **********" << std::endl;
		dog1->printBrain();
		std::cout << "\n********** Dog 2's brain **********" << std::endl;
		dog2->printBrain();

		std::cout << "\n********** copy after Dog 2's brain **********" << std::endl;
		*dog2 = *dog1;
		dog1->setBrain("change!!!!!!!!!!!!!");
		std::cout << "\n********** Dog 1's brain **********" << std::endl;
		dog1->printBrain();
		std::cout << "\n********** Dog 2's brain **********" << std::endl;
		dog2->printBrain();

		std::cout << "\n========== Dog Destroy! ==========" << std::endl;
		delete dog1;
		delete dog2;
	}
	//while (1);
	return 0;
}