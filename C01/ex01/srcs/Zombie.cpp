/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:25:56 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 21:29:07 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Default constructor caled" << std::endl;
}

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << name << " zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Zombie" << " destroyed" << std::endl;
}

void Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name (std::string name)
{
	this->_name = name;
}
