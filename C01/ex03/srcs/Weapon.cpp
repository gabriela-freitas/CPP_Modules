/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:08:31 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 23:20:26 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	std::cout << GREEN;
	std::cout << "Weapon : Default constructor called" << std::endl;
	std::cout << ENDC;
}
Weapon::Weapon(std::string type):
	_type(type)
{
	std::cout << GREEN;
	std::cout << "Weapon : created with type" << std::endl;
	std::cout << ENDC;
}

Weapon::~Weapon() {
	std::cout << RED;
	std::cout << "Weapon" << " destroyed" << std::endl;
	std::cout << ENDC;
}

const std::string &Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
