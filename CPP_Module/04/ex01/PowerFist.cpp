/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:07:13 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:14:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist():
	AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &other):
	AWeapon(other)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
