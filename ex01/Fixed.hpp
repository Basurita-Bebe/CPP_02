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

/*
** Fixed-point number: a real number stored inside an int.
**
**   raw bits:  [ 24 bits integer part | 8 bits fractional part ]
**   value   =  _value / 2^8   (= _value / 256)
**
** Precision (epsilon) is 1 / 256 = 0.00390625.
*/
class Fixed {
private:
    int                 _value;                    // raw bits = real value * 256
    static const int    _fractionalBits = 8;       // shared by all instances (static), never changes (const).
public:
    /* --- Orthodox Canonical Form --- */
    Fixed();                                       // default: value 0
    Fixed(const Fixed &src);                       // creates a NEW object as a copy
    Fixed &operator = (const Fixed &src);          // overwrites an EXSITING object
    ~Fixed();

    /* --- Conversion constructors --- */
    Fixed(const int &n);                           // int -> fixed (n * 256)
    Fixed(const float &n);                         // float -> fixed (roundf(n * 256))

    /* --- Raw access --- */
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    /* --- Conversions back --- */
    int     toInt(void) const;                  // raw >> 8
    float   toFloat(void) const;                // raw / 256.0f
};

/*
** Non-member: the left operand is std::ostream, not Fixed, so it cannot be a
** method of Fixed. It only uses the public toFloat(), so no 'friend' is needed.
*/
std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif
