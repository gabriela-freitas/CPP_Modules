/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:34:35 by gafreita          #+#    #+#             */
/*   Updated: 2022/10/21 16:42:04 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}

// Dynamically allocated memory is allocated on Heap, and non-static and
// local variables get memory allocated on Stack

// The new operator denotes a request for memory allocation on the Free Store.
// If sufficient memory is available, a new operator initializes the memory and
// returns the address of the newly allocated and initialized memory to the pointer variable.
