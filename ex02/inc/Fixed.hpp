#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _value;
	static const int _fractionalBits = 8;

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

	/** Devuelve el valor crudo */
	int getRawBits(void) const;
	/** Asigna el valor crudo */
	void setRawBits(int const raw);

	/** Convierte a float */
	float toFloat(void) const;
	/** Convierte a int */
	int toInt(void) const;

	/* =============================
		Sobrecarga de operadores
	============================= */

	/** Comparaciones */
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/** Aritméticos */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	/** Incremento/Decremento */
	// pre-incremento (++a)
	Fixed &operator++();
	// post-incremento (a++)
	Fixed operator++(int);
	// pre-decremento (--a)
	Fixed &operator--();
	// post-decremento (a--)
	Fixed operator--(int);

	/* =============================
		Funciones estáticas min/max 
	============================= */
	// static no pertenece a ninguna instancia
	// se llama con Fixed::min(a, b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

/** Sobrecarga de << */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
