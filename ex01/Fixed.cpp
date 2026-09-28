/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:24:48 by bruno             #+#    #+#             */
/*   Updated: 2026/09/08 16:46:08 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>				// roundf

/* ============================ OCF (from ex00) ============================= */

// Default constructor: a new Fixed represents 0.
// Initializer list sets _value directly (no "construct then assign").
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor: called when a NEW object is created from another one.
// Uses the initializer list instead of operator=, so no "Copy assignment operator called" line. 
Fixed::Fixed(const Fixed &src) : _value(src._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment: called when an EXISTING object is overwritten (b = a;).
Fixed &Fixed::operator = (const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src._value;
	return (*this);
}

// Destructor: nothing to free (no dynamic memory), only prints the trace.
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Returns the raw bits (value x 256). const: does not modify the object.
int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

// Sets the raw bits directly, without any conversion.
void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

/* =========================== CONVERSIONS (ex01) =========================== */

// int -> fixed: move the integer into the upper 24 bits (x 256).
// Example: 10 -> 2560.
// Written as n * 256 instead of n << 8: left-shifting a NEGATIVE int is undefined behavior in C++98.
Fixed::Fixed(const int &n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;                          // = to n *(1 << _fractionalBits)
}

// float -> fixed: scale by 256 and round to the nearest integer.
// Example: 42.42 x 256 = 10859.52 -> roundf -> 10860.
// roundf instead of a cast: a cast truncates (10859), loses precision.
Fixed::Fixed(const float &n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

// fixed -> int: drop the 8 fractional bits (10860 >> 8 = 42).
int Fixed::toInt(void) const {
    std::cout << "toInt member function called" << std::endl;
    return (_value >> _fractionalBits);
}

// fixed -> float: divide by 256 as a FLOAT, not as an int, otherwise the fractional part is lost (10860 / 256.0f = 42.4219).
// That is why c prints 42.4219 and not 42.42: precision is 1/256.
float Fixed::toFloat(void) const {
    std::cout << "toFloat member function called" << std::endl;
    return (_value / (float)(1 << _fractionalBits));
}

// Insertion operator: prints the float representation.
// Returns the stream so calls can be chained: (cout << a) << b.
std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return (o);
}
