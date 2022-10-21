/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:08:26 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 23:19:13 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB():
	_weapon(NULL)
{
	std::cout << GREEN;
	std::cout << "HumanB : Default constructor called" << std::endl;
	std::cout << ENDC;
}

HumanB::HumanB(std::string name):
	_name(name),
	_weapon(NULL)
{
	std::cout << GREEN;
	std::cout << "HumanB created" << std::endl;
	std::cout << ENDC;
}

HumanB::~HumanB() {
	std::cout << RED;
	std::cout << "HumanB" << " destroyed" << std::endl;
	std::cout << ENDC;
}

void HumanB::attack(void)
{
	std::cout << BLUE;
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
	std::cout << ENDC;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
