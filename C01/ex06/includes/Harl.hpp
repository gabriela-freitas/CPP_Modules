/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:40 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/26 13:03:09 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <map>


class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string start_level );
	private:
		typedef void (Harl::*f_pointer)();
		std::string func_names[4];
		f_pointer function[4];
		void debug(void);
		void info( void );
		void warning( void );
		void error( void );
		void print_level(int i);
};
#endif
