/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:25:56 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 21:12:44 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
Zombie::Zombie() {
	// TODO (default constructor)
}

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << name << " zombie created" << std::endl;
}

void Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Zombie" << " destroyed" << std::endl;
}
