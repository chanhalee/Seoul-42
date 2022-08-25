#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../hpp/Bureaucrat.hpp"
#include "../hpp/PresidentialPardonForm.hpp"
#include "../hpp/RobotomyRequestForm.hpp"
#include "../hpp/ShrubberyCreationForm.hpp"
#include "./Form.hpp"

class Form;

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern();
	Form *makeForm(const string &name, const string &target) const;
	Form *makePForm(const string &target) const;
	Form *makeRForm(const string &target) const;
	Form *makeSForm(const string &target) const;
	void doNothing(void) const;

};

#endif