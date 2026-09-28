/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:40:20 by bruno             #+#    #+#             */
/*   Updated: 2026/09/10 16:04:33 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/*
** A 2D point with fixed-point coordinates.
** x and y are const: once a Point is built, it can never move.
*/
class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        /* --- Orthodox Canonical Form --- */
        Point();                                        // (0, 0)
        Point(Point const &src);
        Point &operator=(Point const &src);             // cannot copy const members (see Point.cpp)
        ~Point();

        Point(float const x, float const y);

        /* --- Getters: return const references (no copy, read-only) --- */
        Fixed const &getX(void) const;
        Fixed const &getY(void) const;
};

// true if 'point' is strictly inside triangle (a, b, c); false on an edge or vertex.
bool            bsp(Point const a, Point const b, Point const c, Point const point);

#endif
