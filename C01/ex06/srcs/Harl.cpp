/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:01:11 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:31 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Harl.hpp"
#include "ex05.hpp"

Harl::Harl()
{
	func_names[0] = "DEBUG";
	func_names[1] = "INFO";
	func_names[2] = "WARNING";
	func_names[3] = "ERROR";
	function[0] = &Harl::debug;
	function[1] = &Harl::info;
	function[2] = &Harl::warning;
	function[3] = &Harl::error;
	std::cout << GREEN <<"Harl created" << ENDC << std::endl;
}

Harl::~Harl() {
	std::cout << RED << "Harl" << " destroyed" << ENDC << std::endl;
}

void Harl::debug(void)
{
	std::cout << ">>>>> DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-\
cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void){
	std::cout << ">>>>> INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << ">>>>> WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\
years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void){
	std::cout << ">>>>> ERROR" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::print_level (int i)
{
	f_pointer p;

	while (i < 4)
	{
		p = this->function[i++];
		(this->*p)();
	}
}

void Harl::complain(std::string start_level)
{
	int level;

	level = -1;
	for (int i = 0; i < 4; i++)
	{
		if (this->func_names[i] == start_level)
		{
			level = i;
			break ;
		}
	}
	switch (level)
	{
		case (0):
			print_level(0);
			break;
		case (1):
			print_level(1);
			break;
		case (2):
			print_level(2);
			break;
		case (3):
			print_level(3);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	}
}
