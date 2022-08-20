#include "../hpp/ScavTrap.hpp"


ScavTrap::ScavTrap():ClapTrap(), gateKeeperMode(false)
{
	cout<<"[ScavTrap] Default constructor called"<<endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(string name): ClapTrap(name), gateKeeperMode(false)
{
	cout<<"[ScavTrap] String constructor called"<<endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
:ClapTrap(ScavTrap.name), gateKeeperMode(false)
{
	cout<<"[ScavTrap] Copy constructor called"<<endl;
	hitPoints = ScavTrap.hitPoints;
	energyPoints = ScavTrap.energyPoints;
	attackDamage = ScavTrap.attackDamage;
}
ScavTrap::~ScavTrap()
{
	cout<<"[ScavTrap] Destructor called"<<endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
	cout<<"[ScavTrap]Copy assignment operator called"<<endl;
	name = ScavTrap.name;
	hitPoints = ScavTrap.hitPoints;
	energyPoints = ScavTrap.energyPoints;
	attackDamage = ScavTrap.attackDamage;
	gateKeeperMode = ScavTrap.gateKeeperMode;
	return (*this);
}
void ScavTrap::attack(const string &target)
{
	if (energyPoints <= 0)
	{
		cout<<"[ScavTrap] attack failed: not enough energy"<<endl;
	}
	else if (hitPoints <= 0)
	{
		cout<<"[ScavTrap] attack failed: hitPoint zero"<<endl;
	}
	else
	{
		--energyPoints;
		cout<<"[ScavTrap] "<<name<<" Attacks "<<target<<", causing "<<attackDamage<<" points of damage!"<<endl;
	}
}

void ScavTrap::guardGate()
{
	if (gateKeeperMode)
	{
		cout<<"[ScavTrap] already in gateKeeperMode"<<endl;
	}
	else
	{
		gateKeeperMode = true;
		cout<<"[ScavTrap] is now in Gate keeper mode."<<endl;
	}
}