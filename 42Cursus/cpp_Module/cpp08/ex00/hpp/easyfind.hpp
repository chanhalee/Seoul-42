#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::find;

template <typename T>
typename T::iterator easyfind(T& h, int n)
{
	typename T::iterator it = find(h.begin(), h.end(), n);
	if (it == h.end())
		throw std::exception();
	return (it);
}

#endif