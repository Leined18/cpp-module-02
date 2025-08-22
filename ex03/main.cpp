/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2025/08/22 14:27:29 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

/** 
 * Función auxiliar para imprimir si un punto está dentro del triángulo
 */
void testPoint(Point const &a, Point const &b, Point const &c, Point const &p, const std::string &label)
{
    std::cout << label << " (" << p.getX().toFloat() << ", " << p.getY().toFloat() << "): "
              << (bsp(a, b, c, p) ? "inside" : "outside") << std::endl;
}

int main(void)
{
    // Triángulo
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Puntos de prueba
    Point inside(2, 2);
    Point outside(10, 10);
    Point edge(5, 0);
    Point vertex(0, 0);

    std::cout << "Testing points for triangle ABC:" << std::endl;

    testPoint(a, b, c, inside, "Inside point");
    testPoint(a, b, c, outside, "Outside point");
    testPoint(a, b, c, edge, "Edge point");
    testPoint(a, b, c, vertex, "Vertex point");

    return 0;
}
