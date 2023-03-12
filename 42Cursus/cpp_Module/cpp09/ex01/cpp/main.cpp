#include "../hpp/RPN.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
	string str("");
	int i = 0;

	if (argc<2)
	{
		cout<<"No args input"<<endl;
	}
	try {
		while(++i < argc)
		{
			str.append(argv[i]);
			if(i+1 != argc)
			{
				str.append(" ");
			}
		}
		RPN rpn(str);
		float result = rpn.calculate();
		cout<<result<<endl;
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	return 0;
}