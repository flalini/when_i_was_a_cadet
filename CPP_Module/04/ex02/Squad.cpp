/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:22:07 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 18:27:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
	count(0), units(0)
{
}

Squad::Squad(Squad const &other):
	count(0), units(0)
{
	this->count = 0;
	for (int i = 0; i < other.getCount(); i++)
		this->push(other.getUnit(i)->clone());
}

Squad::~Squad()
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
	}
}

Squad &Squad::operator=(Squad const &other)
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
		this->units = 0;
	}
	this->count = 0;
	for (int i = 0; i < other.getCount(); i++)
		this->push(other.getUnit(i)->clone());
	return (*this);
}

int Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine *Squad::getUnit(int index) const
{
	if (index < 0 || this->count == 0 || index >= count)
		return (0);
	return (this->units[index]);
}

int Squad::push(ISpaceMarine *unit)
{
	if (!unit)
		return (this->count);
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			if (this->units[i] == unit)
				return (this->count);
		ISpaceMarine **copy = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
			copy[i] = this->units[i];
		delete[] this->units;
		this->units = copy;
	}
	else
		this->units = new ISpaceMarine*[1];
	this->units[this->count] = unit;
	return (++(this->count));
}
