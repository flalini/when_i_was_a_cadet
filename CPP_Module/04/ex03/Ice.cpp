/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:22:00 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 21:32:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
}

Ice::Ice(Ice const &other):
	AMateria("ice", other.getXP())
{
}

Ice::~Ice()
{
}

AMateria *Ice::clone(void) const
{
	Ice *cpy = new Ice(*this);
	return (cpy);
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
