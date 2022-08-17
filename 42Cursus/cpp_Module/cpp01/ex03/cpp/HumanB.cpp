#include "../hpp/HumanB.hpp"


HumanB::HumanB(string name):name(name)
{
	weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::attack()
{
	cout<<name<<" attacks with their ";
	if (weapon == NULL)
		cout<<"bear hands"<<endl;
	else
		cout<<weapon->getType()<<endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}