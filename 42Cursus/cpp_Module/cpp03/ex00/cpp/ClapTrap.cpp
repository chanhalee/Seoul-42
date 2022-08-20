#include "../hpp/ClapTrap.hpp"

ClapTrap::ClapTrap()
:name("NoName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	cout<<"Default constructor called"<<endl;
	
}
ClapTrap::ClapTrap(string name)
:name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	cout<<"String constructor called"<<endl;
}
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
:name(clapTrap.name), hitPoints(clapTrap.hitPoints), energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage)
{
	cout<<"Copy constructor called"<<endl;
}
ClapTrap::~ClapTrap()
{
	cout<<"Destructor called"<<endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	cout<<"Copy assignment operator called"<<endl;
	name = clapTrap.name;
	hitPoints = clapTrap.hitPoints;
	energyPoints = clapTrap.energyPoints;
	attackDamage = clapTrap.attackDamage;
	return (*this);
}
void ClapTrap::attack(const string &target)
{
	if (energyPoints <= 0)
	{
		cout<<"attack failed: not enough energy"<<endl;
	}
	else if (hitPoints <= 0)
	{
		cout<<"attack failed: hitPoint zero"<<endl;
	}
	else
	{
		--energyPoints;
		cout<<name<<" Attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		cout<<"takeDamage failed: Dead already"<<endl;
	}
	else
	{
		hitPoints -= amount;
		cout<<name<<" damaged. "<<amount<<endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		cout<<"repair failed: not enough energy"<<endl;
	}
	else if (hitPoints <= 0)
	{
		cout<<"repair failed: hitPoint zero"<<endl;
	}
	else
	{
		--energyPoints;
		hitPoints += amount;
		cout<<name<<" repaired. "<<amount<<endl;
	}
}