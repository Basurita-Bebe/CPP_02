/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:43:20 by bruno             #+#    #+#             */
/*   Updated: 2026/09/10 16:10:02 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Same class as ex02, with the trace messages removed so that the BSP tests in main print only their results.

/* ============================ OCF (from ex00) ============================= */

// Default constructor: a new Fixed represents 0 (initializer list).
Fixed::Fixed() : _value(0) {
    //std::cout << "Fixed default constructor called" << std::endl;
}

// Copy constructor: creates a NEW object from another one.
Fixed::Fixed(const Fixed &src) : _value(src._value) {
    //std::cout << "Fixed copy constructor called" << std::endl;
}

// Copy assignment: overwrites an EXISTING object.
Fixed &Fixed::operator = (const Fixed &src) {
    //std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src._value;
	return (*this);
}

// Destructor: nothing to free (no dynamic memory).
Fixed::~Fixed() {
    //std::cout << "Fixed Cestructor called" << std::endl;
}

// Returns the raw bits (value x 256). const: does not modify the object.
int     Fixed::getRawBits(void) const {
    //std::cout << "Fixed getRawBits member function called" << std::endl;
	return (_value);
}

// Sets the raw bits directly, without any conversion.
void    Fixed::setRawBits(int const raw) {
    //std::cout << "Fixed setRawBits member function called" << std::endl;
	_value = raw;
}

/* ======================== CONVERSIONS (from ex01) ========================= */

// int -> fixed (x 256). n * 256 instead of n << 8: shifting a negative int is undefined behavior in C++98.
Fixed::Fixed(const int &n) {
    //std::cout << "Fixed int constructor called" << std::endl;
    _value = n << _fractionalBits;                                   
}

// float -> fixed: scale by 256, roundf to the nearest (a cast would truncate).
Fixed::Fixed(const float &n) {
    //std::cout << "Fixed float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

// fixed -> int: drop the 8 fractional bits.
int Fixed::toInt(void) const {
    //std::cout << "Fixed toInt member function called" << std::endl;
    return (_value >> _fractionalBits);
}

// fixed -> float: divide by 256 as a FLOAT to keep the fraction.
float Fixed::toFloat(void) const {
    //std::cout << "Fixed toFloat member function called" << std::endl;
    return (_value / (float)(1 << _fractionalBits));
}

// Prints the float value; returns the stream so calls chain.
std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return (o);
}

/* ====================== COMPARISON OPERATORS (from ex02) ================== */
// Same scale on both sides (x 256): comparing raw values is enough.

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

/* ====================== ARITHMETIC OPERATORS (from ex02) ================== */

// (a x 256) + (b x 256) = (a + b) x 256: add raw values directly.
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

// raw x raw doubles the scale and overflows an int above ~181.
Fixed   Fixed::operator*(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * rhs._value) / (1 << _fractionalBits));
    return (result);
}

// raw / raw loses the scale: multiply the numerator by 256 FIRST.
// Division by zero is not handled (the subject accepts a crash).
Fixed   Fixed::operator/(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * (1 << _fractionalBits)) / rhs._value);
    return (result);
}

/* ==================== INCREMENT / DECREMENT (from ex02) =================== */
// Step = 1 raw unit = epsilon = 1/256.

// Pre (++a): modify, return *this by reference.
Fixed   &Fixed::operator++() {
    ++_value;
    return (*this);
}

// Post (a++): dummy int marks the postfix version; returns the OLD value.
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

/* ========================== MIN / MAX (from ex02) ========================= */
// static: called as Fixed::min(a, b). Return a reference, no copy.
// const overloads needed for const objects.

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
