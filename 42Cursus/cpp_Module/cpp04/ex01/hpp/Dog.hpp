#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

using std::cout;
using std::endl;
using std::string;

class Dog :public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &dog);
	Dog &operator =(const Dog &dog);
	void makeSound() const;
	void setBrain(const string str);
	void printBrain(void);
	~Dog();
};
#endif