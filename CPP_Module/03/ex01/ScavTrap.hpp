/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:45:25 by ijang             #+#    #+#             */
/*   Updated: 2021/04/12 20:52:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class ScavTrap
{
	private:
		unsigned int HitPoints;
		unsigned int MaxHitPoints;
		unsigned int EnergyPoints;
		unsigned int MaxEnergyPoints;
		int Level;
		std::string Name;
		unsigned int MeleeAttackDamage;
		unsigned int RangedAttackDamage;
		unsigned int ArmorDamageReduction;

		static std::string Quotes[5];

	public:
		ScavTrap();
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &other);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void challengeNewcomer();
};

#endif
