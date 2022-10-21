/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:07:43 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 21:30:14 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int N = 8;

	zombies = zombieHorde(N, "Zombies_colective");
	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "]";
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
