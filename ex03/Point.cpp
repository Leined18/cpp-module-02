#include "Point.hpp"

/** Constructor por defecto */
Point::Point() : _x(0), _y(0)
{
}

/** Constructor desde float */
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

/** Constructor de copia */
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

/** Operador de asignación */
Point &Point::operator=(const Point &other)
{
	// Como los atributos son const, no pueden reasignarse.
	// Implementación vacía: no cambia nada.
	(void)other;
	return (*this);
}

/** Destructor */
Point::~Point()
{
}

Fixed Point::getX() const
{
	return (_x);
}
Fixed Point::getY() const
{
	return (_y);
}
