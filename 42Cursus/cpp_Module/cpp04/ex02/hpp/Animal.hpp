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
	Animal(void);
	Animal(string type);
	Animal(const Animal &animal);
	Animal &operator =(const Animal &animal);
	virtual void makeSound() const = 0; // 가상함수 마킹 (함수의 몸체가 없다는 것을 컴파일러에게 명시적으로 알림)
	void makeSound(string sound) const;
	string getType() const;
	virtual ~Animal();
};
#endif