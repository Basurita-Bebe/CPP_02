/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:09:25 by bruno             #+#    #+#             */
/*   Updated: 2026/09/10 12:41:04 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {
    
    /* Reference triangle used across tests
    //     c(0,4)
    //     |\
    //     | \
    //     |  \
    //     a---b
    //   (0,0) (4,0) */
    Point   a(0.0f, 0.0f);
    Point   b(4.0f, 0.0f);
    Point   c(0.0f, 4.0f);

    // Test 1: clearly inside the triangle -> expect true
    Point   inside(1.0f, 1.0f);
    std::cout << "Test 1 (inside):    "
              << (bsp(a, b, c, inside) ? "true" : "false")
              << " (expected true)" << std::endl;
    
    // Test 2: clearly outside the triangle -> expect false
    Point   outside(10.0f, 10.0f);
    std::cout << "Test 2 (outside):   "
              << (bsp(a, b, c, outside) ? "true" : "false")
              << "  (expected false)" << std::endl;
              
    // Test 3: exactly on a vertex (point == a) -> expect false
    Point   onVertex(0.0f, 0.0f);
    std::cout << "Test 3 (on vertex):   "
              << (bsp(a, b, c, onVertex) ? "true" : "false")
              << "  (expected false)" << std::endl;

    // Test 4: exactly on edge (midpoint of a-b, y=0 between x=0 and x=4) -> expect false
    Point   onEdge(2.0f, 0.0f);
    std::cout << "Test 4 (on edge):   "
              << (bsp(a, b, c, onEdge) ? "true" : "false")
              << " (expected false)" << std::endl;
              
    // Test 5: just bearly inside -> expect true
    Point   nearEdge(0.1f, 0.1f);
    std::cout << "Test 5 (near edge, in):   "
              << (bsp(a, b, c, nearEdge) ? "true" : "false")
              << " (expected true)" << std::endl;
    
    return (0);
}