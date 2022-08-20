#include "../hpp/FragTrap.hpp"


FragTrap::FragTrap():ClapTrap()
{
	cout<<"[FragTrap] Default constructor called"<<endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(string name): ClapTrap(name)
{
	cout<<"[FragTrap] String constructor called"<<endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &FragTrap)
:ClapTrap(FragTrap.name)
{
	cout<<"[FragTrap] Copy constructor called"<<endl;
	hitPoints = FragTrap.hitPoints;
	energyPoints = FragTrap.energyPoints;
	attackDamage = FragTrap.attackDamage;
}
FragTrap::~FragTrap()
{
	cout<<"[FragTrap] Destructor called"<<endl;
}
FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
	cout<<"[FragTrap]Copy assignment operator called"<<endl;
	name = FragTrap.name;
	hitPoints = FragTrap.hitPoints;
	energyPoints = FragTrap.energyPoints;
	attackDamage = FragTrap.attackDamage;
	return (*this);
}
void FragTrap::attack(const string &target)
{
	if (energyPoints <= 0)
	{
		cout<<"[FragTrap] attack failed: not enough energy"<<endl;
	}
	else if (hitPoints <= 0)
	{
		cout<<"[FragTrap] attack failed: hitPoint zero"<<endl;
	}
	else
	{
		--energyPoints;
		cout<<"[FragTrap] "<<name<<": Attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<endl;
	}
}

void FragTrap::highFivesGuys()
{
	cout<<"[FragTrap] "<<name<<": HIGH FIVE!"<<endl;
}