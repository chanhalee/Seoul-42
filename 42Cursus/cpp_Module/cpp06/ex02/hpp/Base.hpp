#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

class Base
{
public:
	virtual ~Base();
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif