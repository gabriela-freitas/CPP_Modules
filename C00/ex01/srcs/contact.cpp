/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/18 20:01:00 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

void	contact::print_truncated(void)
{
	// std::cout << contact::
}

void	contact::print(void)
{
	std::cout << "First name: " << contact::first_name << std::endl;
	std::cout << "Last name: " << contact::last_name << std::endl;
	std::cout << "Nickname: " << contact::nickname << std::endl;
	std::cout << "Phone number: " << contact::phone_number << std::endl;
	std::cout << "Darkest secret: " << contact::darkest_secret << std::endl;
}

void	contact::new_contact(void)
{
	while (true)
	{
		std::cout << "Input first name: ";
		std::getline(std::cin, contact::first_name);
		if (contact::first_name == "")
			std::cout << "This field can't be empty, try again" << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Input last name: ";
		std::getline(std::cin, contact::last_name);
		if (contact::last_name == "")
			std::cout << "This field can't be empty, try again" << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Input nickname: ";
		std::getline(std::cin, contact::nickname);
		if (contact::nickname == "")
			std::cout << "This field can't be empty, try again" << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Input Phone Number: ";
		std::getline(std::cin, contact::phone_number);
		if (contact::phone_number == "")
			std::cout << "This field can't be empty, try again" << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Input darkest secret: ";
		std::getline(std::cin, contact::darkest_secret);
		if (contact::darkest_secret == "")
			std::cout << "This field can't be empty, try again" << std::endl;
		else
			break ;
	}
}
