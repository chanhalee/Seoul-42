#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class PhoneBook
{
private:
	Contact contacts[8];
	int		size;
public:
	PhoneBook();
	void	add_contact(string info[]);
	void	printList();
	int		printSingle(int index);
};

#endif