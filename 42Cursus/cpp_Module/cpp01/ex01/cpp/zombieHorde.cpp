#include "../hpp/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	int counter;
	if (N <= 0)
		return (NULL);

	Zombie *horde = new Zombie[N];
	if (horde == NULL)
		return (NULL);
	counter = -1;
	while (++counter < N)
	{
		horde[counter].setName(name);
	}
	return horde;
}