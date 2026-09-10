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

static Fixed    crossSign(Point const &p1, Point const &p2, Point const &p);

// Computes the signed cross product of vectors (p1->p2) and (p1->p).
// Sign indicates which side of the line p1->p2 the point p lies on.
static Fixed    crossSign(Point const &p1, Point const &p2, Point const &p) {
    
    static Fixed    result;
    
    result = ((p2.getX() - p1.getX()) * (p.getY() - p1.getY())) - ((p2.getY() - p1.getY()) * (p.getX() - p1.getX()));
    return (result);
}

// Returns true if `point` lies strictly inside triangle (a, b, c).
// A point is inside only if it's on the same side of all 3 edges.
// Any zero cross product means the point sits on an edge/vertex -> false.
bool    bsp(Point const a, Point const b, Point const c, Point const point) {

    // Signed distance of `point` from each edge of the triangle
    Fixed   d1 = crossSign(a, b, point);        // side relative to edge a->b
    Fixed   d2 = crossSign(b, c, point);        // side relative to edge b->c
    Fixed   d3 = crossSign(c, a, point);        // side relative to edge c->a

    // On a vertex or exactly on an edge -> not strictly inside
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return (false);
    
    // Point is inside only if all 3 signs agree (all same side)
    bool    hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool    hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return (!(hasNeg && hasPos));
}