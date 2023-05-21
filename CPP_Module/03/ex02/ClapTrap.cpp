/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:44:45 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:50:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 100;
	this->MaxEnergyPoints = 100;
	this->Level = 1;
	this->Name = "N4MELE55";
	this->MeleeAttackDamage = 30;
	this->RangedAttackDamage = 20;
	this->ArmorDamageReduction = 5;
	this->Model = "CL4P-TP";

	std::cout << "CL4P-TP <" << this->Name << "> Login" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 100;
	this->MaxEnergyPoints = 100;
	this->Level = 1;
	this->Name = name;
	this->MeleeAttackDamage = 30;
	this->RangedAttackDamage = 20;
	this->ArmorDamageReduction = 5;
	this->Model = "CL4P-TP";

	std::cout << "CL4P-TP <" << this->Name << "> Login" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
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
	this->Model = other.Model;

	std::cout << "CL4P-TP <" << this->Name << "> Login" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP <" << this->Name << "> went AFK" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
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
	this->Model = other.Model;

	return (*this);
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> at range, causing <" << this->RangedAttackDamage
		<< "> points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> at melee, causing <" << this->MeleeAttackDamage
		<< "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < this->ArmorDamageReduction)
		amount = 0;
	else
		amount -= this->ArmorDamageReduction;

	if (amount > this->HitPoints)
		amount = this->HitPoints;
	this->HitPoints -= amount;
	std::cout << this->Model << " <" << this->Name << "> take <"
		<< amount << "> points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->MaxHitPoints - this->HitPoints < amount)
		amount = this->MaxHitPoints - this->HitPoints;
	this->HitPoints += amount;
	std::cout << this->Model << " <" << this->Name << "> is repaired for <"
		<< amount << "> points!" << std::endl;
}
