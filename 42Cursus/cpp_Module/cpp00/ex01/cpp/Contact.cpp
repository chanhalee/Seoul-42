#include "../hpp/Contact.hpp"

Contact::Contact()
{

}

Contact::Contact(string info[])
{
	this->firstName = info[0];
	this->lastName = info[1];
	this->nickname = info[2];
	this->phoneNumber = info[3];
	this->darkestSecret = info[4];
}

void Contact::printListForm(int index = 0) const
{
	cout<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	cout<<index<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	if (firstName.length() > 10)
		cout<<firstName.substr(0, 9)+"."<<"|";
	else
	cout<<firstName<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	if (lastName.length() > 10)
		cout<<lastName.substr(0, 9)+"."<<"|";
	else
		cout<<lastName<<"|";
	cout<<std::setfill(' ')<<std::setw(10);
	if (nickname.length() > 10)
		cout<<nickname.substr(0, 9)+"."<<"|"<<endl;
	else
		cout<<nickname<<"|"<<endl;
}

void Contact::printSingleForm() const
{
    cout<<"first name: "<<firstName<<endl;
    cout<<"last name: "<<lastName<<endl;
    cout<<"nickname: "<<nickname<<endl;
    cout<<"phone number: "<<phoneNumber<<"\n";
    cout<<"darkest secret: "<<darkestSecret<<endl;
}
