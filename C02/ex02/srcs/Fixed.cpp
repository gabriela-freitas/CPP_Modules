/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:29:31 by gafreita          #+#    #+#             */
/*   Updated: 2022/11/19 18:10:59 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*############EX00#################*/

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& param) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed::Fixed(const int num){
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedNum = num << this->_fractional_bits;
}

Fixed::Fixed(const float num){
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(num * (1 << this->_fractional_bits)));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& param)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNum = param.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const{
	return(this->_fixedNum);
}
void Fixed::setRawBits( int const raw ){
	this->_fixedNum = raw;
}

/*############EX01#################*/

float	Fixed::toFloat(void) const{
	return ((float)this->_fixedNum / (float) (1 << this->_fractional_bits));
}

int		Fixed::toInt(void) const{
	return (this->_fixedNum >> this->_fractional_bits);
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& num){
	cout << num.toFloat();

	return (cout);
}

/*############EX02#################*/

/*########## COMPARING OPERATORS ############*/
bool	Fixed::operator> (const Fixed& param){
	return (this->_fixedNum > param._fixedNum);
}
bool	Fixed::operator< (const Fixed& param){
	return (this->_fixedNum < param._fixedNum);
}
bool	Fixed::operator>= (const Fixed& param){
	return (this->_fixedNum >= param._fixedNum);
}
bool	Fixed::operator<= (const Fixed& param){
	return (this->_fixedNum <= param._fixedNum);
}
bool	Fixed::operator== (const Fixed& param){
	return (this->_fixedNum == param._fixedNum);
}
bool	Fixed::operator!= (const Fixed& param){
	return (this->_fixedNum != param._fixedNum);
}

/*####### ARITHMETIC OPERATIONS ############*/

//This operations work the same in fixed numbers
Fixed	Fixed::operator+ (const Fixed& param){
	Fixed res;
	res.setRawBits(this->_fixedNum + param._fixedNum);
	return (res);
}
Fixed	Fixed::operator- (const Fixed& param){
	Fixed res;
	res.setRawBits(this->_fixedNum - param._fixedNum);
	return (res);
}

/*In these ones we need first to typecast it to long long int
in order to deal with overflow and underflow

    Typecast each fix to long long (64 bits)
    Multiply/divide them, yielding the 64-bit intermediate variable illustrated above
    Right-shift/left-shift by 8 to shift out the underflow
    Typecast back to fix to retain only the least significant 32 bits, getting rid of the overflow.
		The result will be a 32-bit fixed point variable with the decimal precisely where we want it

*/
Fixed	Fixed::operator* (const Fixed& param){
	return (Fixed(this->toFloat() * param.toFloat()));
}

Fixed	Fixed::operator/ (const Fixed& param){
	Fixed	result;

	result.setRawBits(((float)this->getRawBits() / param.getRawBits())
			* (1 << this->_fractional_bits));
	return (result);
}

/*########## INCREMENT OPERATORS ###########*/
//post-increment
Fixed&	Fixed::operator++(void){
	*this = Fixed(*this + Fixed(1));
	return (*this);
}
//pre-increment
Fixed	Fixed::operator++(int){
	Fixed res(*this);
	*this = Fixed(*this + Fixed(1));
	return (res);
}

/*########## DECREMENT OPERATORS ###########*/
// post-increment
Fixed&	Fixed::operator--(void){
	*this = Fixed(*this - Fixed(1));
	return (*this);
}
//pre-increment
Fixed	Fixed::operator--(int){
	Fixed res(*this);
	*this = Fixed(*this - Fixed(1));
	return (res);
}

