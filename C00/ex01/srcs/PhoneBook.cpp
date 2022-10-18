/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:38:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/18 23:27:53 by gafreita         ###   ########.fr       */
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

void PhoneBook::search(void)
{
	std::cout << YELLOW << "Saved contacts:" << ENDC << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_truncated(i);
	std::cout << std::endl;
	// TODO: Then, prompt the user again for the index of the entry to display. If the index
	// is out of range or wrong, define a relevant behavior. Otherwise, display the
	// contact information, one field per line.
	contacts[0].print();
}
