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

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;
public:
    Fixed();                                    // Default Constructor
    Fixed(const Fixed &src);                    // Copy Constructor
    Fixed &operator=(const Fixed &src);         // Copy Assignment
    ~Fixed();                                   // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif