#include "../hpp/Fixed.hpp"

int main(void)
{
	Fixed a(1234.4321f);
	Fixed const b( 10 ); 
	Fixed const c( 42.42f );
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed f;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "f is " << f << std::endl;

	std::cout << "======================\n\n";
	std::cout << "(a > b) = " << (a > b) << std::endl;
	std::cout << "(a < b) = " << (a < b) << std::endl;
	std::cout << "(a == b) = " << (a >= b) << std::endl;
	std::cout << "(a != b) = " << (a <= b) << std::endl;
	std::cout << "(a == b) = " << (a == b) << std::endl;
	std::cout << "(a != b) = " << (a != b) << std::endl;
	std::cout << "(a + c) = " << a + c << std::endl;
	std::cout << "(a - c) = " << a - c << std::endl;
	std::cout << "(a * c) = " << a * c << std::endl;
	std::cout << "(a / c) = " << a / c << std::endl;

	std::cout << f << std::endl;
	std::cout << ++f << std::endl;
	std::cout << f << std::endl;
	std::cout << f++ << std::endl;
	std::cout << f << std::endl;

	std::cout << Fixed::max(b, d) << std::endl;


	return(0);
}