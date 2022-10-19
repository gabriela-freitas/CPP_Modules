/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:38:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/19 15:36:01 by gafreita         ###   ########.fr       */
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
	std::cout << BLUE << "Added to your contact list\n" << ENDC << std::endl;
}

void PhoneBook::search(void)
{
	std::string index;

	std::cout << YELLOW << "Saved contacts:" << ENDC << std::endl;
	std::cout << "   INDEX  |" << "FIRST NAME|" << " LAST NAME|" << "  NICKNAME|" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_truncated(i);
	while (1)
	{
		std::cout << std::endl << WHITE << "Index of the entry to display: " << ENDC;
		std::cin >> std::ws;
		std::getline(std::cin, index);
		std::cout << std::endl;
		if ((atoi(index.c_str()) == 0 && index.compare(0, 1, "0")) || (atoi(index.c_str()) < 0 || atoi(index.c_str()) > 7))
			std::cout << RED << "Choose a number between 0 and 7" << ENDC << std::endl;
		else
		{
			this->contacts[atoi(index.c_str())].print();
			break ;
		}
	}
}
