#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
protected:
	string type;
public:
	Animal();
	Animal(string type);
	Animal(const Animal &animal);
	Animal &operator =(const Animal &animal);
	virtual void makeSound() const;
	void makeSound(string sound) const;
	string getType() const;
	virtual ~Animal();
};
#endif