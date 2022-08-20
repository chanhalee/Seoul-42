#include "../hpp/ClapTrap.hpp"
#include "../hpp/ScavTrap.hpp"

int main(void)
{
	ClapTrap ct1;
	ClapTrap ct2("Fanta");
	ScavTrap st1("Dr.pepper");
	ScavTrap st2(st1);

	ct1.attack("Cola");
	ct1.takeDamage(10);
	ct1.beRepaired(10);
	ct2.takeDamage(2);
	ct2.beRepaired(1);
	ct2.attack("Sprite");

	st1.attack("Welch's");
	st1.attack("Welch's");
	st1.takeDamage(10);
	st1.beRepaired(20);
	st2.guardGate();
	st2.guardGate();
}