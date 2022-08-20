#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		std::cout << "========== Default ==========" << std::endl;
	
		//const Animal* j = new Animal();
		const Animal* i = new Cat();

		//delete j; //should not create a leak
		i->makeSound();
		delete i;
	}
	//while (1);
	return 0;
}