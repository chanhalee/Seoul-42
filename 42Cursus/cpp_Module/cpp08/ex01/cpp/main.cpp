#include "../hpp/Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	cout<<"\n====================\n"<<endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printAll();
		Span sp2(sp);
		Span *pp = &sp2;
		sp2 = *pp;
		sp2.printAll();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout<<"\n====================\n"<<endl;
	try{
		std::srand(std::time(NULL));
		vector<int> c;
		while(c.size() < 15000)
			c.push_back(rand() % 50);
		Span sp = Span(15000);
		sp.addNumber(c.begin(), c.end());
		sp.printAll();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}