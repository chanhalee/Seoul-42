#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "./WrongAnimal.hpp"

using std::cout;
using std::endl;
using std::string;

class WrongCat :public WrongAnimal
{
private:
public:
	WrongCat();
	WrongCat(const WrongCat &WrongCat);
	WrongCat &operator =(const WrongCat &WrongCat);
	void makeSound() const;
	~WrongCat();
};
#endif