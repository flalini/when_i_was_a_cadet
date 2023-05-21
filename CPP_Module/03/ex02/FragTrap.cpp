/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:09:29 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:37:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string FragTrap::Quotes[5] = {
	"Hot potato!",
	"Pull pin, throw!",
	"Grenade!",
	"Grenaaaade!",
	"Eat bomb, baddie!"
};

FragTrap::FragTrap()
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
	this->Model = "FR4G-TP";

	std::cout << "FR4G-TP <" << this->Name << "> Login" << std::endl;
}

FragTrap::FragTrap(std::string const &name)
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
	this->Model = "FR4G-TP";

	std::cout << "FR4G-TP <" << this->Name << "> Login" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other)
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

	std::cout << "FR4G-TP <" << this->Name << "> Login" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP <" << this->Name << "> went AFK" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> at sniper rifle, causing <" << this->RangedAttackDamage
		<< "> points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> with axe, causing <" << this->MeleeAttackDamage
		<< "> points of damage!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->EnergyPoints >= 25)
	{
		this->EnergyPoints -= 25;
		std::cout << this->Model << " <" << this->Name << "> : "
			<< FragTrap::Quotes[rand() % 5] << std::endl;
		std::cout << this->Model << " <" << this->Name << "> attacks <" << target
			<< "> at range, causing <" << (rand() % this->RangedAttackDamage)
			<< "> points of damage!" << std::endl;
	}
	else
	{
		std::cout << this->Model << " <" << this->Name <<
			"> is out of energy!" << std::endl;
	}
}
