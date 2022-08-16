#include "../hpp/Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(string name):name(name)
{

}

Zombie::~Zombie()
{
	cout<<name<<": destroyed"<<endl;
}

void Zombie::announce()
{
	cout<<name<<": BraiiiiiiinnnzzzZ..."<<endl;
}

void Zombie::setName(string name)
{
	this->name = name;
}

