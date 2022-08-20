#include "../hpp/Brain.hpp"

Brain::Brain()
{
	cout<<"[Brain] "<<"Default constructor called."<<endl;
}
Brain::Brain(const Brain &brain)
{
	cout<<"[Brain] "<<"Copy constructor called."<<endl;
	int counter;
	counter = -1;
	while (++counter < 100)
		ideas[counter] = brain.ideas[counter];
}
Brain &Brain::operator =(const Brain &brain)
{
	cout<<"[Brain] "<<"Copy assignment operator called."<<endl;
	int counter;
	counter = -1;
	while (++counter < 100)
		ideas[counter] = brain.ideas[counter];
	return (*this);
}
Brain::~Brain()
{
	cout<<"[Brain] "<<"Destructor called."<<endl;
}


void Brain::setBrain(const string str)
{
	int	counter;

	counter = -1;
	while (++counter < 100)
		ideas[counter] = str;
}
void Brain::printBrain(void)
{
	int	counter;

	counter = -1;
	while (++counter < 100)
		cout<<"["<<counter+1<<"] "<<ideas[counter]<<endl;

}