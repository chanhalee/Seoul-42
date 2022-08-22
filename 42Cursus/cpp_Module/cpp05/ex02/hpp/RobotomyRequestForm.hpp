#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./Bureaucrat.hpp"
#include "./Form.hpp"

class Bureaucrat;

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class RobotomyRequestForm: public Form
{
private:
	string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const string target);
	RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
	~RobotomyRequestForm();
	void execute(const Bureaucrat &executor) const;

};

#endif