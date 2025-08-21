#include "Fixed.hpp"

/** Default constructor initializes _value to 0 */
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/** Copy constructor copies another Fixed object */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/** Copy assignment operator copies the raw value, avoiding self-assignment */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

/** Destructor */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/** Returns the raw fixed-point value */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

/** Sets the raw fixed-point value */
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
