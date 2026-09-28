/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:23:36 by bruno             #+#    #+#             */
/*   Updated: 2026/09/09 10:31:37 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>			// roundf

/* ============================ OCF (from ex00) ============================= */

// Default constructor: a new Fixed represents 0.
// Initializer list sets _value directly (no "construct then assign").
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor: called when a NEW object is created from another one.
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

/* ======================== CONVERSIONS (from ex01) ========================= */


// int -> fixed: move the integer into the upper 24 bits (x 256). 10 -> 2560.
// n * 256 instead of n << 8: left-shifting a NEGATIVE int is UB in C++98.
Fixed::Fixed(const int &n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;                                      
}

// float -> fixed: scale by 256 and round to the nearest integer.
// 42.42 x 256 = 10859.52 -> roundf -> 10860 (a cast would truncate to 10859).
Fixed::Fixed(const float &n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

// fixed -> int: drop the 8 fractional bits (10860 >> 8 = 42).
int Fixed::toInt(void) const {
    std::cout << "toInt member function called" << std::endl;
    return (_value >> _fractionalBits);
}

// fixed -> float: divide by 256 as a FLOAT, otherwise the fraction is lost.
float Fixed::toFloat(void) const {
    std::cout << "toFloat member function called" << std::endl;
    return (_value / (float)(1 << _fractionalBits));
}

// Prints the float representation. Returns the stream so calls chain: (cout << a) << b.
std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return (o);
}

/* ======================== COMPARISON OPERATORS (ex02) ===================== */
// Both sides use the same scale (x 256), so comparing the raw values gives
// the same result as comparing the real values: no conversion needed.

bool    Fixed::operator>(Fixed const &rhs) const {
    return (this->_value > rhs._value);
}

bool    Fixed::operator<(Fixed const &rhs) const {
    return (this->_value < rhs._value);
}

bool    Fixed::operator>=(Fixed const &rhs) const {
    return (this->_value >= rhs._value);
}

bool    Fixed::operator<=(Fixed const &rhs) const {
    return (this->_value <= rhs._value);
}

bool    Fixed::operator==(Fixed const &rhs) const {
    return (this->_value == rhs._value);
}

bool    Fixed::operator!=(Fixed const &rhs) const {
    return (this->_value != rhs._value);
}

/* ======================== ARITHMETIC OPERATORS (ex02) ===================== */

// (a x 256) + (b x 256) = (a + b) x 256: the scale is kept, add raw values.
Fixed   Fixed::operator+(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits(this->_value + rhs._value);
    return (result);
}

// Same reasoning as +.
Fixed   Fixed::operator-(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits(this->_value - rhs._value);
    return (result);
}

// (a x 256) x (b x 256) = (a x b) x 256 x 256: the scale is doubled.
Fixed   Fixed::operator*(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * rhs._value) / (1 << _fractionalBits));
    return (result);
}

// (a x 256) / (b x 256) = a / b: the scale is lost.
Fixed   Fixed::operator/(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * (1 << _fractionalBits)) / rhs._value);
    return (result);
}

/* ====================== INCREMENT / DECREMENT (ex02) ====================== */
// Step = 1 raw unit = epsilon = 1/256 (0 -> 0.00390625), as the subject asks.

// Pre-increment (++a): change the object, return it by reference.
Fixed   &Fixed::operator++() {
    ++_value;
    return (*this);
}

// Post-increment (a++): the unused int only tells the compiler it is the postfix version.
// Save a copy, increment, return the OLD value by copy (that is why a++ prints an extra "Copy constructor called").
Fixed   Fixed::operator++(int) {
    Fixed   temp(*this);
    ++_value;
    return (temp);
}

Fixed   &Fixed::operator--() {
    --_value;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed   temp(*this);
    --_value;
    return (temp);
}

/* ============================ MIN / MAX (ex02) ============================ */
// static: no 'this' needed, called as Fixed::min(a, b).
// Return a REFERENCE to one of the arguments (no copy).
// The const overload is required for const objects (like 'b' in main).

Fixed   &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    if (a < b)
        return (a);
    return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    if (a > b)
        return (a);
    return (b);
}
