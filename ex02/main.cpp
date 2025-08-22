/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:16:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/22 13:40:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/**
 * Constructores con temporales.
 * Operadores aritméticos (*).
 * Operadores de incremento (pre y post).
 * Función estática min/max.
 */

int	main(void)
{
	std::cout << "---- CREACIÓN ----" << std::endl;

	Fixed a;                                   // Default constructor
	Fixed const b(Fixed(5.05f) * Fixed(2));    // Multiplicación con temporales

	std::cout << "---- INICIO ----" << std::endl;

	// Mostrar valor inicial de a
	std::cout << "a = " << a << std::endl;

	// Pre-incremento (++a): incrementa antes de usar
	std::cout << "++a = " << ++a << std::endl;

	// Mostrar a después del pre-incremento
	std::cout << "a = " << a << std::endl;

	// Post-incremento (a++): usa el valor, luego incrementa
	std::cout << "a++ = " << a++ << std::endl;

	// Mostrar a después del post-incremento
	std::cout << "a = " << a << std::endl;

	// Mostrar b, que es resultado de la multiplicación
	std::cout << "b = " << b << std::endl;

	// Usar función estática max()
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	std::cout << "---- FIN ----" << std::endl;
	return 0;
}
