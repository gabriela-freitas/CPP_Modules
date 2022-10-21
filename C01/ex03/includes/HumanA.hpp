/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:07:43 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 23:09:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "ex03.hpp"
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon &_weapon;
		std::string _name;
	public:
		HumanA(Weapon &weapon);
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack(void);
};
#endif
