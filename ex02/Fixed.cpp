/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:16:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/22 13:39:22 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/** Constructor por defecto */
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/** Constructor desde int */
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}
/** Constructor desde float */
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractionalBits));
}
/** Constructor de copia */
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
/** Operador de asignación */
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}
/** Destructor */
Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (_value);
}
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

/** Operadores de comparación */
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

/** Operadores aritméticos */
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
		// si divisor = 0 → crash permitido
}

/** Incremento/Decremento */
Fixed &Fixed::operator++()
{
 // pre-incremento
	_value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
 // post-incremento
	Fixed temp(*this);
	_value++;
	return (temp);
}
Fixed &Fixed::operator--()
{
 // pre-decremento
	_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
 // post-decremento
	Fixed temp(*this);
	_value--;
	return temp;
}

/** Funciones estáticas min/max */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

/** Operador << */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
