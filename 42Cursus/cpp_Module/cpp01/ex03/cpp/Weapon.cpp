#include "../hpp/Weapon.hpp"

Weapon::Weapon():type("Bare Hands")
{
	
}

Weapon::Weapon(string type):type(type)
{
}

void Weapon::setType(string type)
{
	this->type = type;
}

const string &Weapon::getType()
{
	return type;
}