/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 09:46:36 by bruno             #+#    #+#             */
/*   Updated: 2026/09/10 16:15:28 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/*
** 2D cross product of the vectors (p1 -> p2) and (p1 -> p):
**
**     (p2.x - p1.x) * (p.y - p1.y)  -  (p2.y - p1.y) * (p.x - p1.x)
**
** Its SIGN tells on which side of the line p1 -> p2 the point p lies:
**     > 0 : left side       < 0 : right side       == 0 : on the line
**
**            p (left, > 0)
**            .
**     p1 ----------> p2
**            .
**            p (right, < 0)
**
** 'static' at file level: the helper is only visible inside bsp.cpp.
*/
static Fixed    crossSign(Point const &p1, Point const &p2, Point const &p) {
    
    static Fixed    result;
    
    result = ((p2.getX() - p1.getX()) * (p.getY() - p1.getY())) - ((p2.getY() - p1.getY()) * (p.getX() - p1.getX()));
    return (result);
}

/*
** A point is inside the triangle if it is on the SAME side of all 3 edges,
** walking around the triangle a -> b -> c -> a.
**
** Checking "same sign" (not "all positive") makes it work whether the
** vertices are given clockwise or counter-clockwise.
**
** The Points are passed by value, as the subject's prototype requires
** (each argument calls the Point copy constructor).
*/
bool    bsp(Point const a, Point const b, Point const c, Point const point) {

    // Signed distance of `point` from each edge of the triangle
    Fixed   d1 = crossSign(a, b, point);        // side relative to edge a->b
    Fixed   d2 = crossSign(b, c, point);        // side relative to edge b->c
    Fixed   d3 = crossSign(c, a, point);        // side relative to edge c->a

    // A zero means 'point' is on a vertex or exactly on an edge -> not strictly inside
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return (false);
    
    // Mixed signs: 'point' is outside at leat on one edge.
    bool    hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool    hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return (!(hasNeg && hasPos));
}
