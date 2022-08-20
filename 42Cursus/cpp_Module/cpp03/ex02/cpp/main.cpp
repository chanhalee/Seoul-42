#include "../hpp/ClapTrap.hpp"
#include "../hpp/ScavTrap.hpp"
#include "../hpp/FragTrap.hpp"

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

	ScavTrap st1("Dr.pepper");
	ScavTrap st2(st1);
	st1.attack("Welch's");
	st1.attack("Welch's");
	st1.takeDamage(10);
	st1.beRepaired(20);
	st2.guardGate();
	st2.guardGate();

	FragTrap ft1("Seven Up");
	FragTrap ft2(ft1);
	ft1.attack("Demi Soda");
	ft1.attack("Demi Soda");
	ft1.takeDamage(10);
	ft1.beRepaired(20);
	ft2.highFivesGuys();
	ft2.highFivesGuys();
}