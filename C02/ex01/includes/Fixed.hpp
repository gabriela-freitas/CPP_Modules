/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:33:37 by gafreita          #+#    #+#             */
/*   Updated: 2022/11/12 21:54:13 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FIXED_HPP__
# define __FIXED_HPP__
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
class Fixed {
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed&	operator= (const Fixed&); // const for safety... not super nesessary
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int _fixedNum;
		const static int _fractional_bits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);



#endif
