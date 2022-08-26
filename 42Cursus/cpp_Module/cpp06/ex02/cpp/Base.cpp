#include "../hpp/Base.hpp"
#include "../hpp/A.hpp"
#include "../hpp/B.hpp"
#include "../hpp/C.hpp"

Base::~Base()
{

}

Base * generate(void)
{
	int randVal;

	std::srand(std::time(NULL));
	randVal = std::rand() % 3;
	if (randVal == 0)
	{
		cout<<"\nrandom result: A created!"<<endl;
		return (new A());
	}
	if (randVal == 1)
	{
		cout<<"\nrandom result: B created!"<<endl;
		return (new B());
	}
	cout<<"\nrandom result: C created!"<<endl;
	return (new C());
}
void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
	{
		cout<<"Instance was A!"<<endl;
		return;
	}
	if (dynamic_cast<B *>(p))
	{
		cout<<"Instance was B!"<<endl;
		return;
	}
	if (dynamic_cast<C *>(p))
	{
		cout<<"Instance was C!"<<endl;
		return;
	}
	cout<<"No matching class"<<endl;
}
void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		cout<<"Instance was A!"<<endl;
		return;
	}
	catch(const std::exception e)
	{

	}
	try
	{
		B b = dynamic_cast<B &>(p);
		cout<<"Instance was B!"<<endl;
		return;
	}
	catch(const std::exception e)
	{
		
	}
	try
	{
		C c = dynamic_cast<C &>(p);
		cout<<"Instance was C!"<<endl;
		return;
	}
	catch(const std::exception e)
	{
		
	}
	cout<<"No matching class"<<endl;
}