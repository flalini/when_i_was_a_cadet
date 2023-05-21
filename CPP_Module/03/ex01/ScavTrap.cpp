/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:47:35 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:39:25 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string ScavTrap::Quotes[5] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!"
};

ScavTrap::ScavTrap()
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 50;
	this->MaxEnergyPoints = 50;
	this->Level = 1;
	this->Name = "N4MELE55";
	this->MeleeAttackDamage = 20;
	this->RangedAttackDamage = 15;
	this->ArmorDamageReduction = 3;

	std::cout << "SC4V-TP <" << this->Name << "> Login" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 50;
	this->MaxEnergyPoints = 50;
	this->Level = 1;
	this->Name = name;
	this->MeleeAttackDamage = 20;
	this->RangedAttackDamage = 15;
	this->ArmorDamageReduction = 3;

	std::cout << "SC4V-TP <" << this->Name << "> Login" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	this->HitPoints = other.HitPoints;
	this->MaxHitPoints = other.MaxHitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->MaxEnergyPoints = other.MaxEnergyPoints;
	this->Level = other.Level;
	this->Name = other.Name;
	this->MeleeAttackDamage = other.MeleeAttackDamage;
	this->RangedAttackDamage = other.RangedAttackDamage;
	this->ArmorDamageReduction = other.ArmorDamageReduction;

	std::cout << "SC4V-TP <" << this->Name << "> Login" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP <" << this->Name << "> went AFK" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	this->HitPoints = other.HitPoints;
	this->MaxHitPoints = other.MaxHitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->MaxEnergyPoints = other.MaxEnergyPoints;
	this->Level = other.Level;
	this->Name = other.Name;
	this->MeleeAttackDamage = other.MeleeAttackDamage;
	this->RangedAttackDamage = other.RangedAttackDamage;
	this->ArmorDamageReduction = other.ArmorDamageReduction;

	return (*this);
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" << this->Name << "> attacks <" << target
		<< "> with pistol, causing <" << this->RangedAttackDamage
		<< "> points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" << this->Name << "> attacks <" << target
		<< "> whit knife, causing <" << this->MeleeAttackDamage
		<< "> points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount < this->ArmorDamageReduction)
		amount = 0;
	else
		amount -= this->ArmorDamageReduction;

	if (amount > this->HitPoints)
		amount = this->HitPoints;
	this->HitPoints -= amount;
	std::cout << "SC4V-TP <" << this->Name << "> take <"
		<< amount << "> points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->MaxHitPoints - this->HitPoints < amount)
		amount = this->MaxHitPoints - this->HitPoints;
	this->HitPoints += amount;
	std::cout << "SC4V-TP <" << this->Name << "> is repaired for <"
		<< amount << "> points!" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	std::cout << "SC4V-TP <" << this->Name << "> : "
		<< ScavTrap::Quotes[rand() % 5] << std::endl;
}
