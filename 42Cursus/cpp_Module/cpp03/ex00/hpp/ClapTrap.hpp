#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class ClapTrap
{
private:
	string	name;
	int		hitPoints;
	int		energyPoints;
	int		attackDamage;
public:
	ClapTrap();
	ClapTrap(string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &clapTrap);
	void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif