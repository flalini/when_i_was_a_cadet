/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:54:21 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 12:20:51 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string const &name):
	name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped" << std::endl;
}

Victim::Victim(Victim const &other):
	name(other.name)
{
	std::cout << "Some random victim called " << this->name << " just popped" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(Victim const &other)
{
	this->name = other.name;
	return (*this);
}

std::string const &Victim::getName(void) const
{
	return (this->name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Victim const &victim)
{
	os << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return (os);
}
