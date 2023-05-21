/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:25:46 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:14:09 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle():
	AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other):
	AWeapon(other)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouu *" << std::endl;
}
