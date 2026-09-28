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

// Default constructor: the origin (0, 0).
// const members MUST be set in the initializer list: they cannot be
// assigned in the constructor body.
Point::Point() : x(0), y(0) {
    //std::cout << "POINT default constructor called" << std::endl;
}

// Copy constructor: builds x and y directly from the source's values.
// This is the only way to "copy" a Point, since the members are const.
Point::Point(Point const &src) : x(src.x), y(src.y) {
    //std::cout << "POINT copy constructor called" << std::endl;
}

// Copy assignment: required by the Orthodox Canonical Form, but x and y are
// const, so they can never be reassigned after construction.
// It does nothing and returns *this: after q = p, q keeps its own values.
// (void)src silences the unused-parameter warning (-Wextra -Werror).
Point &Point::operator=(Point const &src){
    (void)src;             
    return (*this);
}

// Float constructor: each float goes through Fixed(const float &).
Point::Point(float const _x, float const _y) : x(_x), y(_y) {
    //std::cout << "POINT float constructor called" << std::endl;
}

// Destructor: nothing to free.
Point::~Point() {
    //std::cout << "POINT destructor called" << std::endl;
}

// Getters return const references: no copy of the Fixed, and the caller cannot modify the point through them.

Fixed const &Point::getX(void) const {
    //std::cout << "getX function member called" << std::endl;
    return (x);
}

Fixed const &Point::getY(void) const {
    //std::cout << "getY function member called" << std::endl;
    return (y);
}
