/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:39:07 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/13 17:39:11 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include <iostream>

class PhoneBook {
	public:
		PhoneBook();
		PhoneBook(const PhoneBook&);
		~PhoneBook();
		PhoneBook&	operator= (const PhoneBook&); // const for safety... not super nesessary
};

std::ostream&	operator<<(std::ostream&, const PhoneBook&);

#endif

