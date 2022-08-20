#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Fixed
{
private:
	int rawBits;
	static const int FracNum = 8;
public:
	Fixed();
	Fixed(const Fixed &fix);
	Fixed(const int &fixInt);
	Fixed(const float &fixFloat);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);

	// 바교연산
	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;

	// 사칙연산
	Fixed operator+(const Fixed& fixed);
	Fixed operator-(const Fixed& fixed);
	Fixed operator*(const Fixed& fixed);
	Fixed operator/(const Fixed& fixed);

	// 전위증감
	Fixed& operator++();
	Fixed& operator--();

	// 후위증감
	const Fixed operator++(int);
	const Fixed operator--(int);

	static Fixed& min(Fixed &r1, Fixed &r2);
	static Fixed& max(Fixed &r1, Fixed &r2);
	static const Fixed& min(const Fixed &r1, const Fixed &r2);
	static const Fixed& max(const Fixed &r1, const Fixed &r2);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

ostream& operator <<(ostream& outputStream, const Fixed& F);

#endif