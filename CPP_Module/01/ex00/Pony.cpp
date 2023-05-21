/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:46:25 by ijang             #+#    #+#             */
/*   Updated: 2021/04/03 14:20:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string const &name):
	name(name)
{
	if (this->name.length())
		std::cout << "Pony \"" << this->name << "\" was born." << std::endl;
	else
		std::cout << "Nameless Pony was born." << std::endl;
}

Pony::~Pony()
{
	int		half_len = this->name.length() / 2;
	if (half_len)
	{
		std::cout << this->name.substr(0, half_len) << "/"
			<< this->name.substr(half_len, this->name.length() - half_len)
			<< std::endl;
	}
	else if (this->name.length())
		std::cout << "Pony \"" << this->name << "\" is dead." << std::endl;
	else
		std::cout << "Nameless Pony is dead." << std::endl;
}

void Pony::cry(void)
{
	if (this->name.length())
		std::cout << this->name << ": Neigh!" << std::endl;
	else
		std::cout << "Nameless Pony cried." << std::endl;
}
