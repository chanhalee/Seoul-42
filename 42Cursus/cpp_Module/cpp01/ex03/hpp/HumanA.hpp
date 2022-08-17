#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanA
{
private:
	string name;
	Weapon *weapon;
public:
	HumanA();
	HumanA(string name, Weapon &weapon);
	~HumanA();
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif