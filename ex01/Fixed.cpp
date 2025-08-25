/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:10:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/25 09:20:19 by danpalac         ###   ########.fr       */
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
	_value = n << _fractionalBits; // multiplicamos por 2^8
}

/** Constructor desde float */
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractionalBits)); // redondeamos al más cercano
}

/** Constructor de copia */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/** Operador de asignación */
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
	std::cout << *this << " ";
	std::cout << "Destructor called" << std::endl;
}

/** Devuelve el valor crudo */
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

/** Asigna un valor crudo */
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/** Convierte el valor interno a float */
float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

/** Convierte el valor interno a int */
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

/** Sobrecarga de << Funcion externa, por std::ostream*/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
