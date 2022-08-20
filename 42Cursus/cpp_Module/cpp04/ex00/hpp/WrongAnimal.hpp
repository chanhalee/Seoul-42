#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal
{
protected:
	string type;
public:
	WrongAnimal();
	WrongAnimal(string type);
	WrongAnimal(const WrongAnimal &WrongAnimal);
	WrongAnimal &operator =(const WrongAnimal &WrongAnimal);
	virtual void makeSound() const;
	void makeSound(string sound) const;
	string getType() const;
	virtual ~WrongAnimal();
};
#endif