#include "../hpp/Contact.hpp"

void Contact::print_list_form(int index = 0) const
{
	cout<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	cout<<index<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	cout<<first_name<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	cout<<last_name<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	cout<<nick_name<<"|"<<endl;;
}

