#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::find;
using std::stack;

class RPN
{
private:
	stack<string> data;
	float result;
public:
	RPN();
	RPN(const RPN &rpn);
	RPN(const string argv);
	RPN& operator=(const RPN &rpn);
	~RPN();
	float calculate();
	void validateNumber(string num);
	class ErrException : public std::exception
	{
		public:
			const char *what() const throw();
	};

};

#endif