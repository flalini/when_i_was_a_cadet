/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:55:07 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 21:20:57 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type):
	_type(type), _xp(0)
{
}

AMateria::AMateria(std::string const &type, int xp):
	_type(type), _xp(xp)
{
}

AMateria::AMateria(AMateria const &other):
	_type(other._type), _xp(other._xp)
{
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
