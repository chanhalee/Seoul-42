#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Bureaucrat
{
private:
	const string name;
	int	grade;
public:
	Bureaucrat();
	Bureaucrat(string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator =(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	string getName(void) const;
	int getGrade(void) const;
	void promote();
	void demote();
};
ostream &operator <<(ostream &os, const Bureaucrat &bureaucrat);

#endif