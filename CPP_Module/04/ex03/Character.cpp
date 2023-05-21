/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:34:12 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 22:19:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name):
	name(name), equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &other):
	name(other.name), equipped(0)
{
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
}

Character &Character::operator=(Character const &other)
{
	this->name = other.name;
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
	this->equipped = 0;
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = NULL;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->equipped == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->equipped; i++)
		if (this->inventory[i] == m)
			return ;
	this->inventory[this->equipped++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
		return ;
	for (int i = idx; i < 3; i++)
		this->inventory[i] = this->inventory[i + 1];
	this->inventory[3] = NULL;
	this->equipped--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}
