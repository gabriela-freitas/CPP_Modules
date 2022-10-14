/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:38:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/13 17:38:22 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	// TODO (default constructor)
}

PhoneBook::PhoneBook(const PhoneBook& param) {
	// TODO (copy constructor)
	(void)param;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook" << " destroyed" << std::endl;
	// TODO (destructor)
}

PhoneBook& PhoneBook::operator= (const PhoneBook& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const PhoneBook& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

