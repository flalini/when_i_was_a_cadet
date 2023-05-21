/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:21:16 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 17:13:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 120;
	this->MaxEnergyPoints = 120;
	this->Level = 1;
	this->Name = "N4MELE55";
	this->MeleeAttackDamage = 60;
	this->RangedAttackDamage = 20;
	this->ArmorDamageReduction = 5;
	this->Model = "SUP3R-TP";

	std::cout << "SUP3ER-TP <" << this->Name << "> Login" << std::endl;
}

SuperTrap::SuperTrap(std::string const &name)
{
	this->HitPoints = 100;
	this->MaxHitPoints = 100;
	this->EnergyPoints = 120;
	this->MaxEnergyPoints = 120;
	this->Level = 1;
	this->Name = name;
	this->MeleeAttackDamage = 60;
	this->RangedAttackDamage = 20;
	this->ArmorDamageReduction = 5;
	this->Model = "SUP3ER-TP";

	std::cout << "SUP3ER-TP <" << this->Name << "> Login" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &other)
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

	std::cout << "SUP3ER-TP <" << this->Name << "> Login" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUP3ER-TP <" << this->Name << "> went AFK" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
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

void SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}
