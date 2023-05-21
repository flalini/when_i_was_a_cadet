/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:09:21 by ijang             #+#    #+#             */
/*   Updated: 2021/04/12 20:45:50 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class FragTrap
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
		FragTrap();
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		~FragTrap();

		FragTrap &operator=(FragTrap const &other);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void vaulthunter_dot_exe(std::string const & target);
};

#endif
