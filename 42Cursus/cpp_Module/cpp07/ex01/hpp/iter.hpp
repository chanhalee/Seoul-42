#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void iter(T* arr, unsigned int length, void (* fun)(T&))
{
	unsigned int index = 0;
	while (index < length)
	{
		fun(arr[index]);
		index++;
	}
}
// template <class T>
// void iter(T* arr, unsigned int length, void (* fun)(const T&))
// {
// 	unsigned int index = 0;
// 	while (index < length)
// 	{
// 		fun(arr[index]);
// 		index++;
// 	}
// }

template <typename T>
void printIt(T &t)
{
	cout<<t<<endl;
}

template <typename T>
void printItP(T &t)
{
	t += t;
	cout<<t<<endl;
}


#endif