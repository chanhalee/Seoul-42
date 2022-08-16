#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
private:
	string name;
public:
	Zombie();
	~Zombie();
	Zombie(string name);
	void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif