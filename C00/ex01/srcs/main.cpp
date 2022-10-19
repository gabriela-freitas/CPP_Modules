/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:47:52 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/19 15:48:44 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	std::string	user_input;
	std::string	usage_message = "Usage:\nADD - to add a new contact in the PhoneBook\
	\nSEARCH - to search within the Phonebook\nEXIT - to quit the program";

	std::cout << GREEN << usage_message << ENDC << std::endl;
	while (true)
	{
		std::cout << WHITE << ">> " << ENDC;
		std::cin >> std::ws;
		std::getline(std::cin, user_input);
		if (!user_input.compare("ADD"))
			PhoneBook.add();
		else if (!user_input.compare("SEARCH"))
			PhoneBook.search();
		else if (!user_input.compare("EXIT"))
			break;
		else
		std::cout << RED << usage_message << ENDC << std::endl;
	}
	std::cout << BLUE << "Bye bye 🥲 \nSorry to break it to you, but your \
contacts are lost forever 💀" << ENDC << std::endl;
	return (0);
}
