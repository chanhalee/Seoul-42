#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Brain
{
private:
	string ideas[100];
public:
	Brain();
	Brain(const Brain &brain);
	void setBrain(const string str);
	void printBrain(void);
	Brain &operator =(const Brain &brain);
	virtual ~Brain();  
};

#endif