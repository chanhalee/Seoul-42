#include "../hpp/Zombie.hpp"

int main()
{
	cout<<"\n\n==========================="<<endl;
	cout<<"\n\nCreated on Stack\n\n"<<endl;
	randomChump("AAA");
	randomChump("BBB");
	randomChump("CCC");

	cout<<"\n\nCreated on Heap\n\n"<<endl;
	Zombie *d = newZombie("DDD");
	Zombie *e = newZombie("EEE");
	Zombie *f = newZombie("FFF");

	d->announce();
	e->announce();
	f->announce();

	delete d;
	delete e;
	delete f;
	cout<<"\n\n==========================="<<endl;
	return (0);
}