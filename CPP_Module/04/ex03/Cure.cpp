/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:22:02 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 21:33:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():
	AMateria("cure")
{
}

Cure::Cure(Cure const &other):
	AMateria("cure", other.getXP())
{
}

Cure::~Cure()
{
}

AMateria *Cure::clone(void) const
{
	Cure *cpy = new Cure(*this);
	return (cpy);
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals" << target.getName() << "’s wounds *" << std::endl;
}
