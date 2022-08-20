#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "./Animal.hpp"

using std::cout;
using std::endl;
using std::string;

class Dog :public Animal
{
private:
public:
	Dog();
	Dog(const Dog &Dog);
	Dog &operator =(const Dog &Dog);
	void makeSound() const;
	~Dog();
};
#endif