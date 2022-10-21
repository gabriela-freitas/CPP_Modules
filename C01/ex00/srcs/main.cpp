/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:25:53 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 16:36:18 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie;


	zombie = newZombie("Alex");
	randomChump("Ju");
	zombie->announce();
	delete(zombie);
	return (0);
}
