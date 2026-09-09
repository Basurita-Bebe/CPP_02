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

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;
public:
    Fixed();                                        // Default Constructor
    Fixed(const int &n);                            // Int Constructor
    Fixed(const float &n);                          // Float Constructor
    Fixed(const Fixed &src);                        // Copy Constructor
    Fixed &operator = (const Fixed &src);           // Copy Assignment
    ~Fixed();                                       // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt(void) const;                      // Turn to int
    float   toFloat(void) const;                    // Turno into float

    // Comparison operators
    bool    operator>(Fixed const &rhs) const;      
    bool    operator<(Fixed const &rhs) const;      
    bool    operator>=(Fixed const &rhs) const;
    bool    operator<=(Fixed const &rhs) const;      
    bool    operator==(Fixed const &rhs) const;     
    bool    operator!=(Fixed const &rhs) const;     
    
    // Addition / Substraction operators
    Fixed   operator+(Fixed const &rhs) const;      
    Fixed   operator-(Fixed const &rhs) const;

    // Multiplication / Division opeartors
    Fixed   operator*(Fixed const &rhs) const;
    Fixed   operator/(Fixed const &rhs) const;

    // Increment / Decrement operators
    Fixed   &operator++();
    Fixed   operator++(int);
    Fixed   &operator--();
    Fixed   operator--(int);

    //
    static Fixed        &min(Fixed &a, Fixed &b);                   // non-const references
    static Fixed const  &min(Fixed const &a, Fixed const &b);       // const references
    static Fixed        &max(Fixed &a, Fixed &b);
    static Fixed const  &max(Fixed const &a, Fixed const &b);
    
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif