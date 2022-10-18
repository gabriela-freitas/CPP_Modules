/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:39:07 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/18 23:16:35 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include "ex01.hpp"
#include "Contact.hpp"

class PhoneBook {
	public:
	void add (void);
	void search (void);

	private:
	Contact contacts[8];
};


#endif

