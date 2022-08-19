#include "../hpp/Fixed.hpp"

Fixed::Fixed():rawBits(0)
{
	cout<<"Default constructor called"<<endl;
}

Fixed::Fixed(const Fixed &fix)
{
	cout<<"Copy constructor called"<<endl;
	rawBits = fix.rawBits;
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
	this->rawBits = fixed.rawBits;
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


bool Fixed::operator>(const Fixed& fixed) const
{
	return (rawBits > fixed.rawBits);
}
bool Fixed::operator<(const Fixed& fixed) const
{
	return (rawBits < fixed.rawBits);
}
bool Fixed::operator>=(const Fixed& fixed) const
{
	return (rawBits >= fixed.rawBits);
}
bool Fixed::operator<=(const Fixed& fixed) const
{
	return (rawBits <= fixed.rawBits);
}
bool Fixed::operator==(const Fixed& fixed) const
{
	return (rawBits == fixed.rawBits);
}
bool Fixed::operator!=(const Fixed& fixed) const
{
	return (rawBits != fixed.rawBits);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	return (Fixed((this->rawBits + fixed.rawBits) >> FracNum));
}
Fixed Fixed::operator-(const Fixed& fixed)
{
	return (Fixed((this->rawBits - fixed.rawBits) >> FracNum));
}
Fixed Fixed::operator*(const Fixed& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++()
{
	++rawBits;
	return (*this);
}
Fixed& Fixed::operator--()
{
	--rawBits;
	return (*this);
}
const Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	++rawBits;
	return (temp);
}
const Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	--rawBits;
	return (temp);
}

Fixed& Fixed::min(Fixed &r1, Fixed &r2)
{
	if (r1 <= r2)
		return (r1);
	return (r2);
}
Fixed& Fixed::max(Fixed &r1, Fixed &r2)
{
	if (r1 >= r2)
		return (r1);
	return (r2);
}
const Fixed& Fixed::min(const Fixed &r1, const Fixed &r2)
{
	if (r1 <= r2)
		return (r1);
	return (r2);
}
const Fixed& Fixed::max(const Fixed &r1, const Fixed &r2)
{
	if (r1 >= r2)
		return (r1);
	return (r2);
}
