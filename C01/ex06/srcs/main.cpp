/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:43:07 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/26 13:12:52 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex05.hpp"
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << BLUE << "Usage: ./harlFilter [LEVEL]" << std::endl;
	return (0);
}
