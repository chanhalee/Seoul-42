#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./Form.hpp"

class Bureaucrat;

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class PresidentialPardonForm: public Form
{
private:
	string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const string target);
	PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
	~PresidentialPardonForm();
	void execute(const Bureaucrat &executor) const;

};

#endif