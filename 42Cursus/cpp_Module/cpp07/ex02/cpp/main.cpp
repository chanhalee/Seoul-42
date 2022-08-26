#include "../hpp/Array.hpp"
#define MAX_VAL 10
using std::ostream;
template <typename T>
ostream &operator<<(ostream &os, const Array<T> & arr)
{
	os <<"Array: {";
	unsigned int idx = 0;
	while (idx < arr.size())
	{
		os<<arr[idx];
		if (idx != arr.size() -1)
			os<<", ";
		++idx;
	}
	os <<"}"<<endl;
	return (os);
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % MAX_VAL;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL -1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	cout<<numbers<<endl;
    delete [] mirror;//

	cout<<"\n==============================\n"<<endl;
	Array<string> strings(0);
	cout<<strings<<endl;

	cout<<"\n==============================\n"<<endl;
	Array<string> strings1(10);
	try
	{
		strings1[0] = "AAA";
		strings1[1] = "111";
		strings1[2] = "222";
		strings1[5] = "555";
		strings1[9] = "999";
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	cout<<strings1<<endl;
    return 0;
}