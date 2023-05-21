/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:16:30 by ijang             #+#    #+#             */
/*   Updated: 2021/04/06 20:53:42 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
//	type(std::string()), name(std::string())
{
	this->type = std::string();
	this->name = std::string();
	std::cout << "The zombie crawls out of the grave." << std::endl;
}

Zombie::Zombie(std::string const &type, std::string const &name):
	type(type), name(name)
{
	this->call_name();
	std::cout << " crawls out of the grave." << std::endl;
}

Zombie::~Zombie()
{
	this->call_name();
	std::cout << " crawls into the grave." << std::endl;
}

void Zombie::setVar(std::string const &type, std::string const &name)
{
	this->type = type;
	this->name = name;
}

void Zombie::call_name()
{
	std::cout << "<";
	if (this->name.length())
		std::cout << this->name;
	else
		std::cout << "Zombie";
	if (this->type.length())
		std::cout << " (" << this->type << ")";
	std::cout << ">";
}

void Zombie::announce(void)
{
	this->call_name();
	std::cout << " Braiiiiiiinnnssss ..." << std::endl;
}
