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

Fixed::Fixed(const int &integer)
{
	cout<<"Int constructor called"<<endl;
	rawBits = integer << FracNum;
}

Fixed::Fixed(const float &floatingPoint)
{
	cout<<"Float constructor called"<<endl;
	rawBits = (int)roundf(floatingPoint * (1 << FracNum));
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

int Fixed::toInt() const
{
	return (rawBits >> 8);
}

float Fixed::toFloat() const
{
	float	ret;
	int		temp;
	int		counter;

	ret = rawBits >> FracNum;
	temp = rawBits - ((rawBits >> FracNum) << FracNum);
	counter = 0;
	while (++counter <= FracNum)
		if (temp & (1 << (FracNum - counter)))
			ret += (1.0 / (1 << counter));
	return (ret);
}


ostream& operator <<(ostream& outputStream, const Fixed& F)
{
	cout << F.toFloat();
	return outputStream;
}
