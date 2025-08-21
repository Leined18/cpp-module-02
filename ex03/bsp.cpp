#include "Point.hpp"

/**
 * Calcula el valor absoluto del área del triángulo
 * definido por tres puntos.
 */
static Fixed	area(Point const a, Point const b, Point const c)
{
	// Fórmula del determinante /2
	return (Fixed((a.getX().toFloat() * (b.getY().toFloat()
					- c.getY().toFloat()) + b.getX().toFloat()
				* (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat()
				* (a.getY().toFloat() - b.getY().toFloat()))
			/ 2.0f).toFloat() < 0 ? Fixed(-1 * ((a.getX().toFloat()
					* (b.getY().toFloat() - c.getY().toFloat())
					+ b.getX().toFloat() * (c.getY().toFloat()
						- a.getY().toFloat()) + c.getX().toFloat()
					* (a.getY().toFloat() - b.getY().toFloat()))
				/ 2.0f)) : Fixed((a.getX().toFloat() * (b.getY().toFloat()
					- c.getY().toFloat()) + b.getX().toFloat()
				* (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat()
				* (a.getY().toFloat() - b.getY().toFloat())) / 2.0f));
}

/**
 * Devuelve true si point está estrictamente dentro
 * del triángulo abc.
 * Si el punto cae sobre un lado o vértice, devuelve false.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A = area(a, b, c);
	A1 = area(point, b, c);
	A2 = area(a, point, c);
	A3 = area(a, b, point);
	// si el punto está sobre un borde → alguna subárea será 0
	if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
		return (false);
	// El punto está dentro si las áreas coinciden
	return (A == A1 + A2 + A3);
}
