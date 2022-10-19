/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:40 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/19 15:39:33 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

#include "ex01.hpp"

// The contact fields are:
// [0] -> first name,
// [1] -> last name,
// [2] -> nickname,
// [3] -> phone number,
// [4] -> darkest secret
class Contact {
	public:
	Contact();
	void	new_contact(void);
	void	print(void);
	void	print_truncated(int index);

	private:
	std::string fields[5];
	std::string messages[5];
};


#endif
