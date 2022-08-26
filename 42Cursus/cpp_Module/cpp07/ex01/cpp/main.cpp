#include "../hpp/iter.hpp"

int main (void)
{
	int arr1[4] = {1, 2, 3, 4};
	string arr2[6] = {"a", "b", "asdfas", "ASDFAS", "aasd", "hre1231v!@#!@$"};
	double arr3[3] = {1.13213, 124.1231, 31231.21};

	iter(arr1, 4, printIt);
	cout<<endl;
	iter(arr2, 6, printIt);
	cout<<endl;
	iter(arr3, 3, printIt);
	cout<<"\n===================\n"<<endl;
	iter(arr1, 4, printItP);
	cout<<endl;
	iter(arr2, 6, printItP);
	cout<<endl;
	iter(arr3, 3, printItP);

	return 0;
}