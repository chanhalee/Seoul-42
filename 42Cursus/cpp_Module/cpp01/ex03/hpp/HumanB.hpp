#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanB
{
private:
	string name;
	Weapon *weapon;
public:
	HumanB();
	HumanB(string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif