/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:23:36 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 22:54:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource():
	amount(0)
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other):
	amount(0)
{
	for (int i = 0; i < other.amount; i++)
		this->learnMateria(other.sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->amount; i++)
		delete this->sources[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < this->amount; i++)
		delete this->sources[i];
	this->amount = 0;
	for (int i = 0; i < other.amount; i++)
		this->learnMateria(other.sources[i]->clone());
	for (int i = this->amount; i < 4; i++)
		this->sources[i] = NULL;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->amount == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->amount; i++)
		if (this->sources[i] == m)
			return ;
	this->sources[this->amount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->amount; i++)
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());
	return (NULL);
}
