/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:29:09 by gafreita          #+#    #+#             */
/*   Updated: 2022/11/18 09:53:24 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex02.hpp"
#include "Fixed.hpp"

int	main(void)
{
	Fixed a(Fixed(1.5f) / Fixed( 3 ));
	Fixed b(2.0f);
	Fixed c(4.7f);

	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	std::cout << a << " + " << c << " = " << (a + c) << std::endl;
	std::cout << a << " - " << c << " = " << (a - c) << std::endl;
	std::cout << "before: " << b << " after++: " << b++ << std::endl;
	std::cout << "before: " << b << " ++after: " << ++b << std::endl;
	std::cout << "before: " << b << " after--: " << b-- << std::endl;
	std::cout << "before: " << b << " --after: " << --b << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
