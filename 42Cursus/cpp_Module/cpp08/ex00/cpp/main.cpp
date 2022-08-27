#include "../hpp/easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> vec;
	int index;

	index = -1;
	while (++index < 10)
	{
		vec.push_back(index);
	}
	try
	{
		std::vector<int>::iterator iter;
		iter = easyfind(vec, 1);
		cout<<"found!:"<< *iter<<endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout<<"\n======================\n"<<endl;
	try
	{
		std::vector<int>::iterator iter;
		iter = easyfind(vec, 9);
		cout<<"found!:"<< *iter<<endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}