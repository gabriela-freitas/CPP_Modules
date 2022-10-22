/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:52:09 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/22 23:23:05 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//open the file
//copy its content to a string
//make the replacement in the string
//outputing to a file <filename>.replace

#include "ex04.hpp"

int		open_files(char *file_name, std::ofstream &replace_file, std::ifstream &original_file);
void	replace_string(std::string &str_temp, char *str_to_replace, char *new_str);

int	main(int ac, char **argv)
{
	std::ofstream	replace_file;
	std::ifstream	original_file;
	std::string		str_temp;

	if (ac != 4)
		std::cout << BLUE << "Usage: [file_name] [str_to_replace] [new_str]" << ENDC << std::endl;
	else
	{
		if (open_files(argv[2], replace_file, original_file))
		{
			std::getline(original_file, str_temp, '\0');
			replace_string(str_temp, argv[2], argv[3]);
			replace_file << str_temp << EOF;
		}
	}
	return (0);
}
