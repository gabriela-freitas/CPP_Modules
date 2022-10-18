/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:47:52 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/18 23:27:16 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

int	main(void)
{
	PhoneBook PhoneBook;

	//Receive user input :: ADD SEARCH or EXIT
	PhoneBook.add();
	PhoneBook.search();
	return (0);
}
