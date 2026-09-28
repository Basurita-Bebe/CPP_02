/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 09:50:22 by bruno             #+#    #+#             */
/*   Updated: 2026/09/09 11:38:57 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*
** Fixed-point number: a real number stored inside an int.
**
**   raw bits:  [ 24 bits integer part | 8 bits fractional part ]
**   value   =  _value / 2^8   (= _value / 256)
*/
class Fixed {
private:
    int                 _value;                    // raw bits = real value * 256
    static const int    _fractionalBits = 8;       // shared by all instances (static), never changes (const)
public:
    Fixed();                                       // Default Constructor
    Fixed(const Fixed &src);                       // Copy Constructor
    Fixed &operator=(const Fixed &src);            // Copy Assignment
    ~Fixed();                                      // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif
