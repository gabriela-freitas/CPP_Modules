/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:26:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 21:18:32 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>
#include <stdlib.h>
class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce (void);
		void set_name (std::string name);
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
