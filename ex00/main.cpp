/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:19:30 by danpalac          #+#    #+#             */
/*   Updated: 2025/08/25 09:19:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Main function to test Fixed class
int	main(void)
{
	Fixed a;    //Default constructor called
	Fixed b(a); //Copy constructor called
	Fixed c;    //Default constructor called
	c = b; //Copy assignment operator called
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0); //Destructors called at the end of scope
}
