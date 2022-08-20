#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

using std::cout;
using std::endl;
using std::string;

class Cat :public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &cat);
	Cat &operator =(const Cat &cat);
	void makeSound() const;
	void setBrain(const string str);
	void printBrain(void);
	~Cat();
};
#endif