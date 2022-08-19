#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Fixed
{
private:
	int rawBits;
	static const int FracNum = 8;
public:
	Fixed();
	Fixed(const Fixed &fix);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif