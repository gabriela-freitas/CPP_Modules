/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:38:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/18 19:58:40 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

void PhoneBook::add(void)
{
	static int	index = 0;

	if (index == 8)
		index = 0;
	contacts[index].new_contact();
	index ++;
}

void PhoneBook::search(std::string name)
{
	if (name[0])
		contacts[0].print_truncated();
	contacts[0].print();
}
