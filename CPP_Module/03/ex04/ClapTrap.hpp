/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:42:34 by ijang             #+#    #+#             */
/*   Updated: 2021/04/15 19:01:29 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class ClapTrap
{
	protected:
		unsigned int HitPoints;
		unsigned int MaxHitPoints;
		unsigned int EnergyPoints;
		unsigned int MaxEnergyPoints;
		int Level;
		std::string Name;
		unsigned int MeleeAttackDamage;
		unsigned int RangedAttackDamage;
		unsigned int ArmorDamageReduction;

		std::string Model;
	public:
		ClapTrap();
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &other);
		virtual ~ClapTrap();

		ClapTrap &operator=(ClapTrap const &other);

		virtual void rangedAttack(std::string const & target);
		virtual void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
};

#endif
