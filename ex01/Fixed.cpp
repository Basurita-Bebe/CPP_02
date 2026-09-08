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
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src._value;
	return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed::Fixed(const int &n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;                          // = to n *(1 << _fractionalBits)
}

Fixed::Fixed(const float &n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
    std::cout << "toInt member function called" << std::endl;
    return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const {
    std::cout << "toFloat member function called" << std::endl;
    return (_value / (float)(1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return (o);
}