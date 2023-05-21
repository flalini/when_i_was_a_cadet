/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:47:13 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 19:26:33 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	this->type = "";
}

ZombieEvent::~ZombieEvent()
{
}

void ZombieEvent::setZombieType(std::string const &type)
{
	this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string const &name)
{
	return (new Zombie(this->type, name));
}

Zombie *ZombieEvent::randomChump(void)
{
	Zombie *zombie;

	zombie = new Zombie(this->type, ZombieEvent::randomName(10));
	zombie->announce();
	return (zombie);
}

std::string ZombieEvent::randomName(std::string::size_type length)
{
	static std::string chrs =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ _";
	std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<std::string::size_type> pick(0, chrs.length() - 1);
	std::string s;

	while(length--)
		s += chrs[pick(gen)];
	return (s);
}
