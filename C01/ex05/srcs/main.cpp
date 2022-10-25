/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:43:07 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/25 23:05:21 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex05.hpp"
#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("debug");
	harl.complain("error");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("errorEWD");
	return (0);
}
