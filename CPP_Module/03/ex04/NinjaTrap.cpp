/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:47:17 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:44:36 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	this->HitPoints = 60;
	this->MaxHitPoints = 60;
	this->EnergyPoints = 120;
	this->MaxEnergyPoints = 120;
	this->Level = 1;
	this->Name = "N4MELE55";
	this->MeleeAttackDamage = 60;
	this->RangedAttackDamage = 5;
	this->ArmorDamageReduction = 0;
	this->Model = "NINJ4-TP";

	std::cout << "NINJ4-TP <" << this->Name << "> Login" << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &name)
{
	this->HitPoints = 60;
	this->MaxHitPoints = 60;
	this->EnergyPoints = 120;
	this->MaxEnergyPoints = 120;
	this->Level = 1;
	this->Name = name;
	this->MeleeAttackDamage = 60;
	this->RangedAttackDamage = 5;
	this->ArmorDamageReduction = 0;
	this->Model = "NINJ4-TP";

	std::cout << "NINJ4-TP <" << this->Name << "> Login" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other)
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

	std::cout << "NINJ4-TP <" << this->Name << "> Login" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJ4-TP <" << this->Name << "> went AFK" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
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

void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> at shoryuken, causing <" << this->RangedAttackDamage
		<< "> points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << this->Model << " <" << this->Name << "> attacks <" << target
		<< "> with katana, causing <" << this->MeleeAttackDamage
		<< "> points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	if (this->EnergyPoints >= 25)
	{
		this->EnergyPoints -= 25;
		std::cout << this->Model << " <" << this->Name
			<< "> : One for you, one for you, one for you!" << std::endl;
		trap.takeDamage(rand() % this->RangedAttackDamage);
	}
	else
	{
		std::cout << this->Model << " <" << this->Name
			<< "> is out of energy!" << std::endl;
	}
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	std::cout << this->Model << " <" << this->Name
		<< "> : You versus me! Me versus you! Either way!" << std::endl;
	trap.challengeNewcomer();
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	trap.takeDamage(500);
	std::cout << this->Model << " <" << this->Name << "> had a roadkill!" << std::endl;
	std::cout << this->Model << " <" << this->Name << "> : Uh... wasn't me!" <<  std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	std::cout << this->Model << " <" << this->Name
		<< "> : I'm a robot ninja..." << std::endl;
	if (rand() % 4)
	{
		trap.takeDamage(this->MeleeAttackDamage);
	}
	else
	{
		this->takeDamage(10);
		std::cout << this->Model << " <" << this->Name
			<< "> : I'm leaking!" << std::endl;
	}
}
