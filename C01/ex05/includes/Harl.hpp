/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:40 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/25 23:10:46 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <map>

//in C++11 I could use a map with std::function
//But since is not allowed, I mimied the behavior of the map
//using two arrays, one with the names (key) and other with the
//pointer to member function (element)

//The complain function iterates in the names element, and executes
//The function in the same index

class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string level );
	private:
		typedef void (Harl::*f_pointer)();
		std::string func_names[4];
		f_pointer function[4];
		void debug(void);
		void info( void );
		void warning( void );
		void error( void );
};
#endif
