/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:06:28 by bruno             #+#    #+#             */
/*   Updated: 2026/09/08 10:20:46 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor: a new Fixed represents 0.
// Initializer list sets _value directly.
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
