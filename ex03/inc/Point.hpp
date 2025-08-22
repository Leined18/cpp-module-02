#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	Fixed const _x;
	Fixed const _y;

  public:
	/** Constructor por defecto: inicializa en (0,0) */
	Point();
	/** Constructor desde float */
	Point(const float x, const float y);
	/** Constructor de copia */
	Point(const Point &other);
	/** Operador de asignación */
	Point &operator=(const Point &other);
	/** Destructor */
	~Point();

	/** Getters */
	Fixed getX() const;
	Fixed getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
