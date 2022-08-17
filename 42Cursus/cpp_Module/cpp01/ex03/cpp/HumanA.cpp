#include "../hpp/HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon):name(name), weapon(&weapon)
{

}
HumanA::~HumanA(){}

void HumanA::attack()
{
	cout<<name<<" attacks with their "<<weapon->getType()<<endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}