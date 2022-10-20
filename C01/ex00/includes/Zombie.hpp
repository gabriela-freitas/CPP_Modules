/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:26:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/20 23:26:04 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__
#include <iostream>
class Zombie {
	public:
		Zombie();
		Zombie(const Zombie&);
		~Zombie();
		Zombie&	operator= (const Zombie&); // const for safety... not super nesessary
};
std::ostream&	operator<<(std::ostream&, const Zombie&);
#endif
