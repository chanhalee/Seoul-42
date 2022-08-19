#include "../hpp/Fixed.hpp"

Fixed::Fixed():rawBits(0)
{
	cout<<"Default constructor called"<<endl;
}

Fixed::Fixed(const Fixed &fix)
{
	cout<<"Copy constructor called"<<endl;
	rawBits = fix.getRawBits();
}

Fixed::~Fixed()
{
	cout<<"Destructor called"<<endl;
}

Fixed &Fixed::operator=(const Fixed& fixed)
{
	cout<<"Copy assignment operator called"<<endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	cout<<"setRawBits member function called"<<endl;
	rawBits = raw;
}

int Fixed::getRawBits() const
{
	cout<<"getRawBits member function called"<<endl;
	return rawBits;
}
