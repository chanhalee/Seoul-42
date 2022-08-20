#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "./ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class ScavTrap :  public ClapTrap
{
private:
	bool gateKeeperMode;
public:
	ScavTrap();
	ScavTrap(string name);
	ScavTrap(const ScavTrap &clapTrap);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &clapTrap);
	void attack(const string &target);
	void guardGate();
};

#endif