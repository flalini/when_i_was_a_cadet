/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:54:04 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 12:35:13 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string const &name):
	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &other):
	Victim(other.name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(Peon const &other)
{
	this->name = other.name;
	return (*this);
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}
