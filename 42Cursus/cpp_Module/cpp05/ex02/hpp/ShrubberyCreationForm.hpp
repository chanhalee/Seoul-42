#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include <iostream>
#include <fstream>
#include "./Bureaucrat.hpp"
#include "./Form.hpp"

class Bureaucrat;

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class ShrubberyCreationForm: public Form
{
private:
	string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat &executor) const;
};

#endif