#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

using std::cout;
using std::endl;
using std::string;

class Contact
{
private:
	string firstName;
	string lastName;
	string nickname;
	string phoneNumber;
    string darkestSecret;
public:
	Contact();
	Contact(string info[]);
	void printListForm(int index) const;
	void printSingleForm() const;
};

#endif