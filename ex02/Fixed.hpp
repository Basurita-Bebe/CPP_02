/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:43:48 by bruno             #+#    #+#             */
/*   Updated: 2026/09/09 10:26:30 by bruno            ###   ########.fr       */
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
    int                 _value;                    // raw bits = real value x 256
    static const int    _fractionalBits = 8;       // shared by all instances (static), never changes (const)
public:

    /* --- Orthodox Canonical Form --- */
    Fixed();                                        // default: value 0
    Fixed(const Fixed &src);                        // creates a NEW object as a copy
    Fixed &operator = (const Fixed &src);           // overwrites an EXISTING object
    ~Fixed();

    /* --- Conversion constructors --- */
    Fixed(const int &n);                            // int   -> fixed
    Fixed(const float &n);                          // float -> fixed

    /* --- Raw access --- */
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    /* --- Conversions back --- */
    int     toInt(void) const;
    float   toFloat(void) const;

    /* --- Comparison: const because they never modify the object --- */
    bool    operator>(Fixed const &rhs) const;      
    bool    operator<(Fixed const &rhs) const;      
    bool    operator>=(Fixed const &rhs) const;
    bool    operator<=(Fixed const &rhs) const;      
    bool    operator==(Fixed const &rhs) const;     
    bool    operator!=(Fixed const &rhs) const;     
    
    /* --- Arithmetic: return a NEW Fixed by value, operands untouched --- */
    Fixed   operator+(Fixed const &rhs) const;      
    Fixed   operator-(Fixed const &rhs) const;
    Fixed   operator*(Fixed const &rhs) const;
    Fixed   operator/(Fixed const &rhs) const;

    /* --- Increment / decrement (step = epsilon) ---
    ** pre  (++a): modifies and returns *this by reference
    ** post (a++): dummy int parameter distinguishes it; returns the OLD value by copy */
    Fixed   &operator++();
    Fixed   operator++(int);
    Fixed   &operator--();
    Fixed   operator--(int);

    /* --- Increment / decrement (step = epsilon) ---
    ** pre  (++a): modifies and returns *this by reference
    ** post (a++): dummy int parameter distinguishes it; returns the OLD value by copy */
    static Fixed        &min(Fixed &a, Fixed &b);                   
    static Fixed const  &min(Fixed const &a, Fixed const &b);
    static Fixed        &max(Fixed &a, Fixed &b);
    static Fixed const  &max(Fixed const &a, Fixed const &b);
    
};

/*
** Non-member: the left operand is std::ostream, not Fixed, so it cannot be a
** method of Fixed. It only uses the public toFloat(), so no 'friend' is needed.
*/
std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif
