#include "../hpp/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
}

void PhoneBook::add_contact(string info[])
{
	Contact newOne(info);
	int		counter;

	if (size < 8)
	{
		contacts[size] = newOne;
		size = size + 1;
	}
	else
	{
		counter = -1;
		while (++counter < 7)
			contacts[counter] = contacts[counter + 1];
		contacts[counter] = newOne;
	}
}

void PhoneBook::printList()
{
	int	counter;

	counter = -1;
	cout <<"|==========|==========|==========|==========|"<<endl;
	cout <<"|    NUMBER|FIRST_NAME| LAST_NAME|  NICKNAME|"<<endl;
	while (++counter < size)
	{
		contacts[counter].printListForm(counter + 1);
	}
	cout <<"|==========|==========|==========|==========|"<<endl;
}

int PhoneBook::printSingle(int index)
{
	if (index > size || index < 1)
		return (1);
	contacts[index - 1].printSingleForm();
	return (0);
}