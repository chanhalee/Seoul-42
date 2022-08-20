#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "./ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class FragTrap :  public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(string name);
	FragTrap(const FragTrap &clapTrap);
	~FragTrap();
	FragTrap &operator=(const FragTrap &clapTrap);
	void attack(const string &target);
	void highFivesGuys(void);
};

#endif