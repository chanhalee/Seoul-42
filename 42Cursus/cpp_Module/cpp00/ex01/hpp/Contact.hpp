#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
private:
	char first_name[10];
	char last_name[10];
	char nick_name[10];
	char phone_number[10];
	char darkest_secret[10];

public:
	const char *get_first_name();
	const char *get_last_name();
	const char *get_nick_name();
	const char *get_phone_number();
	const char *get_darkest_secret();
};

#endif