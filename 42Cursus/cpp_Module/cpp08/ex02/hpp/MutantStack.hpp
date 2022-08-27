#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <deque>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

template <typename T>
class MutantStack: public std::stack<T>
{
private:
public:
	MutantStack(){}
	MutantStack(const MutantStack &ms){(*this) = ms; return (*this);}
	MutantStack &operator=(const MutantStack &ms){(*this) = ms; return (*this);}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() {return (this->c.begin());}
	iterator end() {return (this->c.end());}
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() {return (this->c.rbegin());}
	reverse_iterator rend() {return (this->c.rend());}
	~MutantStack(){}
};

#endif