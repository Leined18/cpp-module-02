#include "Point.hpp"

/**
 * Calcula el valor absoluto del área del triángulo definido por tres puntos.
 * 
 * Fórmula usada (shoelace / determinante):
 *   Área = 1/2 * | x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) |
 * 
 * Se devuelve un Fixed porque se trabaja con números de punto fijo.
 * El valor absoluto garantiza que el área sea siempre positiva.
 * a = 1, b = 2, c = 3
 * Aquí / 2.0f es dividir entre 2, que es exactamente la misma operación que multiplicar por 1/2.0f
 */

/**
 * Calcula el determinante del triángulo definido por tres puntos.
 */
static Fixed triangleDeterminant(Point const a, Point const b, Point const c)
{
    return Fixed(
        (a.getX() * (b.getY() - c.getY()) +
         b.getX() * (c.getY() - a.getY()) +
         c.getX() * (a.getY() - b.getY())) / 2.0f
    );
}

/**
 * Calcula el valor absoluto del área del triángulo.
 */
static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed det = triangleDeterminant(a, b, c);
    return (det < Fixed(0)) ? Fixed(-1)*det : det; // aplica el valor absoluto
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
