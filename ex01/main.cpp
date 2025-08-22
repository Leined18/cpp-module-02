/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:27:55 by daniel            #+#    #+#             */
/*   Updated: 2025/08/22 13:28:00 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    std::cout << "---- CREACIÓN ----" << std::endl;

    Fixed a;                  // Default constructor
    Fixed const b(10);        // Int constructor
    Fixed const c(42.42f);    // Float constructor
    Fixed const d(b);         // Copy constructor

    std::cout << "---- ASIGNACIÓN ----" << std::endl;

    a = Fixed(1234.4321f);    // Temp (Float constructor) + Copy assignment

    std::cout << "---- OUTPUT ----" << std::endl;

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "---- TO INT ----" << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "---- FIN ----" << std::endl;
    return 0;
}
