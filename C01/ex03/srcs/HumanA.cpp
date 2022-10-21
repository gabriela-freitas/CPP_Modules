/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:08:24 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 23:17:28 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon):
	_weapon(weapon)
{
	std::cout << GREEN;
	std::cout << "HumanA : Default constructor called" << std::endl;\
	std::cout << ENDC;
}

HumanA::HumanA(std::string name, Weapon &weapon):
	_weapon(weapon),
	_name(name)
	{
		std::cout << GREEN;
		std::cout << "HumanA created" << std::endl;
		std::cout << ENDC;
	}

HumanA::~HumanA() {
	std::cout << RED;
	std::cout << "HumanA" << " destroyed" << std::endl;
	std::cout << ENDC;
	// TODO (destructor)
}

void HumanA::attack(void)
{
	std::cout << BLUE;
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
	std::cout << ENDC;
}

