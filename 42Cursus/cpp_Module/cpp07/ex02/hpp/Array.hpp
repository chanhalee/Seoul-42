#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Array
{
private:
	unsigned int arrSize;
	T *arr;
public:
	Array():arrSize(0), arr(nullptr)
	{
		cout<<"[Array] "<<"Default constructor called."<<endl;
	}
	Array(const Array &array):arrSize(array.size())
	{
		unsigned int idx;
		cout<<"[Array] "<<"Copy constructor called."<<endl;
		if (arrSize == 0)
			arr = nullptr;
		else
		{
			arr = new T[arrSize];
			idx = 0;
			while (idx < arrSize)
			{
				arr[idx] = array[idx];
				++idx;
			}
		}
	}
	Array &operator=(const Array &array)
	{
		cout<<"[Array] "<<"Copy assignment operator called."<<endl;
		if (arr != nullptr)
			delete[] arr;
		arrSize = array.size();
		unsigned int idx;
		if (arrSize == 0)
			arr = nullptr;
		else
		{
			arr = new T[arrSize];
			idx = 0;
			while (idx < arrSize)
			{
				arr[idx] = array[idx];
				++idx;
			}
		}
		return (*this);
	}
	~Array()
	{
		cout<<"[Array] "<<"Destructor called."<<endl;
		if (arr != nullptr)
		delete[] arr;
	}
	Array(unsigned int n):arrSize(n), arr(new T[n]){}
	T &operator[](const unsigned int idx) const
	{
		if (idx >= arrSize)
			throw std::exception();
		return (arr[idx]);
	}
	unsigned int size() const
	{
		return (arrSize);
	}
};
#endif