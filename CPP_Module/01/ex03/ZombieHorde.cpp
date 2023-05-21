/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:16:24 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 19:36:08 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int size):
	type(std::string()), size(size)
{
	if (size > 0)
	{
		this->zombies = new Zombie[size];
		for (int i = 0; i < size; i++)
			this->zombies[i].setVar(this->type, ZombieHorde::randomName(10));
	}
	else
		std::cout << "I can't handle negative numbers." << std::endl;
}

ZombieHorde::ZombieHorde(std::string const &type, int size):
	type(type), size(size)
{
	if (size > 0)
	{
		this->zombies = new Zombie[size];
		for (int i = 0; i < size; i++)
			this->zombies[i].setVar(this->type, ZombieHorde::randomName(10));
	}
	else
		std::cout << "I can't handle negative numbers." << std::endl;
}

ZombieHorde::~ZombieHorde()
{
	if (this->type.length())
		std::cout << "Horde " << this->type;
	else
		std::cout << "Horde";
	std::cout << " will collapse." << std::endl;
	delete[] this->zombies;
}

std::string ZombieHorde::randomName(std::string::size_type length)
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

void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->size; i++)
		this->zombies[i].announce();
}
