/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:29:09 by gafreita          #+#    #+#             */
/*   Updated: 2022/11/16 20:24:41 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex02.hpp"
#include "Fixed.hpp"

int	main(void)
{
	Fixed a(Fixed( 5.05f ) * Fixed( 2 ));
	Fixed b(2.0f);
	Fixed c;

	std::cout << "a value " << a << std::endl;
	std::cout << "b value " << b << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	return (0);
}
