/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:58:16 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 21:33:10 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde horde(10);
	horde.announce();

	ZombieHorde walkerHorde("Walker", 10);
	walkerHorde.announce();

	return (0);
}
