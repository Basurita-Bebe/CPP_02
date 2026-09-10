/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:46:46 by bruno             #+#    #+#             */
/*   Updated: 2026/09/10 16:12:17 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(Point const &src) : x(src.x), y(src.y) {
    //std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(Point const &src){
    (void)src;                                                      // silence unused-parameter warning
    return (*this);
}

Point::Point(float const _x, float const _y) : x(_x), y(_y) {
    //std::cout << "Float constructor called" << std::endl;
}

Point::~Point() {
    //std::cout << "Destructor called" << std::endl;
}

Fixed const &Point::getX(void) const {
    //std::cout << "getX function member called" << std::endl;
    return (x);
}

Fixed const &Point::getY(void) const {
    //std::cout << "getY function member called" << std::endl;
    return (y);
}
