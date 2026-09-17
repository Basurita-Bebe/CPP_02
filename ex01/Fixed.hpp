/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:23:17 by bruno             #+#    #+#             */
/*   Updated: 2026/09/09 09:18:06 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;
public:
    Fixed();                                    // Default Constructor
    Fixed(const int &n);                        // Int Constructor
    Fixed(const float &n);                      // Float Constructor
    Fixed(const Fixed &src);                    // Copy Constructor
    Fixed &operator = (const Fixed &src);       // Copy Assignment
    ~Fixed();                                   // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt(void) const;                  // Turn to int
    float   toFloat(void) const;                // Turno into float
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif