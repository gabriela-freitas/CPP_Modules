/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:41:31 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/12 17:50:36 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < (int) strlen(argv[i]); j++)
			argv[i][j] = toupper(argv[i][j]);
		if (i < argc - 1)
			std::cout << argv[i] << " ";
		else
			std::cout << argv[i] << std::endl;
	}
}
