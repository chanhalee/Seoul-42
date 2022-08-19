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
	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

ostream& operator <<(ostream&, const Fixed&);

#endif