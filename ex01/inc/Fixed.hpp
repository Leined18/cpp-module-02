#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath> // para roundf
# include <iostream>

class Fixed
{
  private:
	int _value;                          
		// Valor almacenado en formato punto fijo
	static const int _fractionalBits = 8;
		// Bits de parte fraccional (siempre 8)

  public:
	/** Constructor por defecto */
	Fixed();

	/** Constructor desde int */
	Fixed(const int n);

	/** Constructor desde float */
	Fixed(const float f);

	/** Constructor de copia */
	Fixed(const Fixed &other);

	/** Operador de asignación */
	Fixed &operator=(const Fixed &other);

	/** Destructor */
	~Fixed();

	/** Devuelve el valor crudo (raw) */
	int getRawBits(void) const;

	/** Asigna un valor crudo (raw) */
	void setRawBits(int const raw);

	/** Convierte a float */
	float toFloat(void) const;

	/** Convierte a int */
	int toInt(void) const;
};

/** Sobrecarga del operador << para imprimir Fixed */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
