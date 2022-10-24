/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:52:09 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/24 17:00:45 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//open the file
//copy its content to a string
//make the replacement in the string
//outputing to a file <filename>.replace

#include "ex04.hpp"

int		open_files(std::string file_name, std::ofstream &replace_file, std::ifstream &original_file);
void	replace_string(std::string &str_temp, std::string str_to_replace, std::string new_str);

int	main(int ac, char **argv)
{
	std::ofstream	replace_file;
	std::ifstream	original_file;
	std::string		str_temp;

	if (ac != 4)
		std::cout << BLUE << "Usage: [file_name] [str_to_replace] [new_str]" << ENDC << std::endl;
	else
	{
		if (open_files(argv[1], replace_file, original_file))
		{
			std::getline(original_file, str_temp, '\0');
			replace_string(str_temp, argv[2], argv[3]);
			replace_file << str_temp;
		}
	}
	std::cout << BLUE << argv[1] << ".replace created" << ENDC << std::endl;
	return (0);
}

int		open_files(std::string file_name, std::ofstream &replace_file, std::ifstream &original_file)
{
	original_file.open(file_name.c_str());
	if (!original_file.is_open())
	{
		std::cout << "Couldn't open file" << std::endl;
		return (false);
	}
	file_name += ".replace";
	replace_file.open(file_name.c_str());
	if (!replace_file.is_open())
	{
		std::cout << "Couldn't create file" << std::endl;
		return (false);
	}
	return (true);
}

void	replace_string(std::string &str_temp, std::string str_to_replace, std::string new_str)
{
	std::size_t index = 0;

	while (true)
	{
		index = str_temp.find(str_to_replace, index);
		if (index == std::string::npos)
			break ;
		str_temp.erase(index, str_to_replace.length());
		str_temp.insert(index, new_str);
	}
}
