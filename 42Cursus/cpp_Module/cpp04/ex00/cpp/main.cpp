#include "../hpp/Dog.hpp"
#include "../hpp/Cat.hpp"
#include "../hpp/WrongCat.hpp"

int main()
{
	{
		std::cout << "========== OK ==========" << std::endl;
		std::cout << "meta 생성 : " << std::endl;
		const Animal* meta = new Animal();
		std::cout << "j 생성 : " << std::endl;
		const Animal* j = new Dog();
		std::cout << "i 생성 : " << std::endl;
		const Animal* i = new Cat();

		std::cout <<  "\nmeta의 type : " << meta->getType() << " " << std::endl;
		std::cout <<  "j의 type : " << j->getType() << " " << std::endl;
		std::cout <<  "i의 type : " << i->getType() << " \n" << std::endl;

		std::cout << "i의 makeSound : ";
		i->makeSound(); // will output the cat sound!
		std::cout << "j의 makeSound : ";
		j->makeSound();
		std::cout << "meta의 makeSound : ";
		meta->makeSound();

		std::cout << "\nmeta 해제 : " << std::endl;
		delete meta;
		std::cout << "j 해제 : " << std::endl;
		delete j;
		std::cout << "i 해제 : " << std::endl;
		delete i;
	}

	{
		std::cout << "\n\n========== Wrong ==========" << std::endl;
		std::cout << "wani 생성 : " << std::endl;
		const WrongAnimal* wani = new WrongAnimal();
		std::cout << "wcat 생성 : " << std::endl;
		const WrongAnimal* wcat = new WrongCat();

		std::cout << "\nwani의 type : " << wani->getType() << " " << std::endl;
		std::cout << "wcat의 type : " << wcat->getType() << " \n" << std::endl;

		std::cout << "wani의 makeSound : ";
		wani->makeSound();
		std::cout << "wcat의 makeSound : ";
		wcat->makeSound();

		std::cout << "\nwani 해제 : " << std::endl;
		delete wani;
		std::cout << "wcat 해제 : " << std::endl;
		delete wcat;
	}
	
	return 0;
}