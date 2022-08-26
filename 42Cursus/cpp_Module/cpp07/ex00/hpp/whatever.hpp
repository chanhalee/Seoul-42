#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void swap(T &val1, T &val2)
{
	T temporary;

	temporary = val1;
	val1 = val2;
	val2 = temporary;
}

template <typename T>
T min(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	return val2;
}

template <typename T>
T max(T val1, T val2)
{
	if (val1 > val2)
		return val1;
	return val2;
}

#endif