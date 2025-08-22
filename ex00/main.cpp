#include "Fixed.hpp"

/** Main function to test Fixed class */
int	main(void)
{
	Fixed a;    /** Default constructor called */
	Fixed b(a); /** Copy constructor called */
	Fixed c;    /** Default constructor called */
	c = b; /** Copy assignment operator called */
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0); /** Destructors called at the end of scope */

	a.setRawBits(1);
	b.setRawBits(2);
	c.setRawBits(3);

	Fixed d(a); /** Copy constructor called for object d */
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	return (0);
}
