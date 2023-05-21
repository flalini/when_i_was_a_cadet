/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:54:02 by ijang             #+#    #+#             */
/*   Updated: 2021/04/08 00:01:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type):
	type(type)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}

std::string const &Weapon::getType(void) const
{
	return (this->type);
}
