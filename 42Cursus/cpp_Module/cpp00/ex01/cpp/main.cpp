#include "../hpp/Contact.hpp"
#include "../hpp/PhoneBook.hpp"

int add_contact(PhoneBook &book)
{
    string inputs[5];
    cout<<"first name: ";
	std::getline(std::cin, inputs[0]);
	std::getline(std::cin, inputs[0]);
	if (std::cin.eof() || inputs[0].empty())
        return (1);
    cout<<"last name: ";
	std::getline(std::cin, inputs[1]);
	if (std::cin.eof() || inputs[1].empty())
        return (1);
    cout<<"nickname: ";
	std::getline(std::cin, inputs[2]);
	if (std::cin.eof() || inputs[2].empty())
        return (1);
    cout<<"phone number: ";
	std::getline(std::cin, inputs[3]);
	if (std::cin.eof() || inputs[3].empty())
        return (1);
    cout<<"darkest secret: ";
	std::getline(std::cin, inputs[4]);
	if (std::cin.eof() || inputs[4].empty())
        return (1);
	book.add_contact(inputs);
	return (0);
}

int main()
{
	std::string	input;
	PhoneBook phoneBook;

	input = "";
	while (input != "EXIT")
	{
		cout<<"enter Command:";
		cin>>input;
		if (input == "ADD")
		{
			if (add_contact(phoneBook))
				std::cout<<"Wrong Input!!"<<std::endl;
		}
		else if (input == "SEARCH")
		{
			phoneBook.printList();
			cout<<"enter Number:";
			cin>>input;
			if (input.length() == 1 && input.at(0) <= '8' && input.at(0) >= '1')
			{
				if(phoneBook.printSingle(input.at(0) - '0'))
					std::cout<<"Wrong Number!!"<<std::endl;
			}
			else
				std::cout<<"Wrong Input!!"<<std::endl;
		}
		else if (input != "EXIT")
			std::cout<<"Wrong Input!!"<<std::endl;
	}
}
