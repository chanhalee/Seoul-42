#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

using std::cout;
using std::endl;

class Contact
{
private:
	char first_name[10];
	char last_name[10];
	char nick_name[10];
	char phone_number[10];
	char darkest_secret[10];

public:
	void print_list_form(int index) const;
};

#endif