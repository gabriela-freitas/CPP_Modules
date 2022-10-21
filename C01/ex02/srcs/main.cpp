/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:34:57 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 22:02:11 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = NULL;
	std::string &stringREF = str;

	stringPTR = &str;
	std::cout << "Memory adress of string var: " << &str << std::endl;
	std::cout << "Memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

}
