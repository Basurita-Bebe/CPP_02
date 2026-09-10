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

class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(Point const &src);
        Point &operator=(Point const &src);
        Point(float const x, float const y);
        ~Point();

        Fixed const &getX(void) const;
        Fixed const &getY(void) const;
};

bool            bsp(Point const a, Point const b, Point const c, Point const point);

#endif