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

Fixed::Fixed() : _value(0) {
    //std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
    //std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &src) {
    //std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src._value;
	return (*this);
}

Fixed::~Fixed() {
    //std::cout << "Fixed Cestructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    //std::cout << "Fixed getRawBits member function called" << std::endl;
	return (_value);
}

void    Fixed::setRawBits(int const raw) {
    //std::cout << "Fixed setRawBits member function called" << std::endl;
	_value = raw;
}

// int CONSTRUCTOR
Fixed::Fixed(const int &n) {
    //std::cout << "Fixed int constructor called" << std::endl;
    _value = n << _fractionalBits;                                      // = to n *(1 << _fractionalBits)
}

// float CONSTRUCTOR
Fixed::Fixed(const float &n) {
    //std::cout << "Fixed float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

// toINt 
int Fixed::toInt(void) const {
    //std::cout << "Fixed toInt member function called" << std::endl;
    return (_value >> _fractionalBits);
}

// toFloat
float Fixed::toFloat(void) const {
    //std::cout << "Fixed toFloat member function called" << std::endl;
    return (_value / (float)(1 << _fractionalBits));
}

// operator<<
std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return (o);
}

/*****   ****   ***   **   * EXERCISE 02 *   **   ***   ****   *****/

// comparison
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

// addition & substraction
Fixed   Fixed::operator+(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits(this->_value + rhs._value);
    return (result);
}

Fixed   Fixed::operator-(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits(this->_value - rhs._value);
    return (result);
}

// multiplication & division
Fixed   Fixed::operator*(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * rhs._value) / (1 << _fractionalBits));
    return (result);
}

Fixed   Fixed::operator/(Fixed const &rhs) const {
    Fixed   result;
    result.setRawBits((this->_value * (1 << _fractionalBits)) / rhs._value);
    return (result);
}

// Incremention & Decreation
Fixed   &Fixed::operator++() {
    ++_value;
    return (*this);
}

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

// Min & Max
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
