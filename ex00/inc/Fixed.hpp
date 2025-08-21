#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * Class Fixed represents a fixed-point number
 * in Orthodox Canonical Form.
 * Constructor por defecto → inicializa el valor.
 * Constructor de copia → crea un objeto copiando otro.
 * Operador de asignación (operator=) → copia el valor de un objeto ya existente a otro ya construido.
 * Destructor → libera recursos al destruir el objeto.
 */
class Fixed
{
  private:
	int _value;
	static const int _fractionalBits = 8;

  public:
	Fixed();                              // Default constructor
	Fixed(const Fixed &other);            // Copy constructor
	Fixed &operator=(const Fixed &other); // Copy assignment operator
	~Fixed();                             // Destructor

	int getRawBits(void) const;     // Returns raw fixed-point value
	void setRawBits(int const raw); // Sets raw fixed-point value
};

#endif
