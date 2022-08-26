#include "../hpp/Base.hpp"
#include "../hpp/A.hpp"
#include "../hpp/B.hpp"
#include "../hpp/C.hpp"

int main (void)
{
	Base *base;
	base = new A();
	identify(base);
	delete base;
	cout<<"\n===================\n"<<endl;
	base = new C();
	identify(*base);
	delete base;
	cout<<"\n===================\n"<<endl;
	base = new B();
	identify(*base);
	delete base;
	cout<<"\n===================\n"<<endl;
	base = generate();
	identify(base);
	delete base;
	cout<<"\n===================\n"<<endl;
	return (0);
}