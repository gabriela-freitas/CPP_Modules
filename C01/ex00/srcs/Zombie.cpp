/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:25:56 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/20 23:25:57 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
Zombie::Zombie() {
	// TODO (default constructor)
}
Zombie::Zombie(const Zombie& param) {
	// TODO (copy constructor)
	(void)param;
}
Zombie::~Zombie() {
	std::cout << "Zombie" << " destroyed" << std::endl;
	// TODO (destructor)
}
Zombie& Zombie::operator= (const Zombie& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const Zombie& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}
