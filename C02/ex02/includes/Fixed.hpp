/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:33:37 by gafreita          #+#    #+#             */
/*   Updated: 2022/11/16 20:21:09 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FIXED_HPP__
# define __FIXED_HPP__
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
class Fixed {
	private:
		int _fixedNum;
		const static int _fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed&	operator= (const Fixed&); // const for safety... not super nesessary

		/*########## COMPARING OPERATORS ############*/
		bool	operator> (const Fixed& param);
		bool	operator< (const Fixed& param);
		bool	operator>= (const Fixed& param);
		bool	operator<= (const Fixed& param);
		bool	operator== (const Fixed& param);
		bool	operator!= (const Fixed& param);

		/*####### ARITHMETIC OPERATIONS ############*/
		Fixed	operator+ (const Fixed& param);
		Fixed	operator- (const Fixed& param);
		Fixed	operator/ (const Fixed& param);
		Fixed	operator* (const Fixed& param);

		// /*########## INCREMENT OPERATORS ###########*/
		// Fixed&	operator++ (void);
		// Fixed&	operator++ (int);

		// /*########## DECREMENT OPERATORS ###########*/
		// Fixed&	operator-- (void);
		// Fixed&	operator-- (int);

		// /*####public overloaded member functions#######*/
		// static Fixed& min(Fixed& a, Fixed& b);
		// static Fixed& min(const Fixed& a, const Fixed& b);
		// static Fixed& max(Fixed& a, Fixed& b);
		// static Fixed& max(const Fixed& a, const Fixed& b);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);



#endif
