#include "../hpp/ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1;
	ClapTrap ct2("Fanta");

	ct1.attack("Cola");
	ct1.takeDamage(10);
	ct1.beRepaired(10);
	ct2.takeDamage(2);
	ct2.beRepaired(1);
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
	ct2.attack("Sprite");
}