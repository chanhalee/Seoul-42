#include "../hpp/Zombie.hpp"

int main()
{
	int	counter;
	int	hordeSize;

	cout<<"\n\n==========================="<<endl;
	cout<<"\n\nTest Horde\n\n"<<endl;
	hordeSize = 10;
	Zombie *horde = zombieHorde(hordeSize, "Zoombinis");
	if (horde == NULL)
		return(1);
	counter = -1;
	while (++counter < hordeSize)
	{
		horde[counter].announce();
	}
	delete []horde;
	return (0);
}