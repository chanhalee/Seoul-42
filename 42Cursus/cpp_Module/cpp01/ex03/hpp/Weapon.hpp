#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
private:
	string type;
public:
	Weapon();
	Weapon(string type);
	Weapon(const Weapon &weapon);
	const string &getType();
	void setType(const string type);
};

#endif