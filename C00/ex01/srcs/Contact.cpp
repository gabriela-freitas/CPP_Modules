/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/19 23:30:24 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

Contact::Contact()
{
	this->messages[0] = "First name";
	this->messages[1] = "Last name";
	this->messages[2] = "Nickname";
	this->messages[3] = "Phone number";
	this->messages[4] = "Darkest secret";
}

void	Contact::print_truncated(int index)
{
	if (this->fields[0].length())
	{
		std::cout << std::setfill (' ') << std::setw (10);
 		std::cout << index << "|";
	}
	else
		return ;
	for (int i = 0; i < 3; i ++)
	{
		if (this->fields[i].length() > 10)
			std::cout << this->fields[i].substr(0, 9) << ".";
		else
		{
			std::cout << std::setfill (' ') << std::setw (10);
 			std::cout << this->fields[i];
		}
		std::cout << "|";
		if (i == 2)
			std::cout << std::endl;
	}
	return ;
}

void	Contact::print(void)
{
	for (int i = 0; i < 5 ; i++)
		std::cout << "* " << this->messages[i] << ": " << this->fields[i] << std::endl;
	std::cout << std::endl;
}

void	Contact::new_contact(void)
{
	for (int i = 0; i < 5; i ++)
	{
		while (true)
		{
			std::cout << "Input " << this->messages[i] << ": ";
			std::getline(std::cin, this->fields[i]);
			if (this->fields[i] == "")
				std::cout << "This field can't be empty, try again" << std::endl;
			else
				break ;
		}
	}
}
