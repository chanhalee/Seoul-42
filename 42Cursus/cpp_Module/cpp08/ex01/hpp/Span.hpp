#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::find;
using std::vector;

class Span
{
private:
	unsigned int maxSize;
	vector<int> data;
public:
	Span();
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();
	Span(unsigned int n);
	Span &addNumber(int newOne);
	Span &addNumber(const vector<int>::iterator &begin,const  vector<int>::iterator &end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void printAll();
	class SpanFullException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class SpanException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
#endif