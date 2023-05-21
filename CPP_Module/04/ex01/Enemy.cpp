/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:42 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:53:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

Enemy::Enemy():
	type(std::string()), hp(0)
{
}

Enemy::Enemy(int hp, std::string const &type):
	type(type), hp(hp)
{
}

Enemy::Enemy(Enemy const &other):
	type(other.type), hp(other.hp)
{
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator=(Enemy const &other)
{
	this->type = other.type;
	this->hp = other.hp;
	return (*this);
}

std::string const &Enemy::getType(void) const
{
	return (this->type);
}

int Enemy::getHP(void) const
{
	return (this->hp);
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	if (this->hp < damage)
		this->hp = 0;
	else
		this->hp -= damage;
}
