/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:02:19 by ijang             #+#    #+#             */
/*   Updated: 2021/04/08 00:02:59 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		const Weapon *weapon;

	public:
		HumanB(std::string const &name);
		~HumanB();

		void setWeapon(const Weapon &weapon);
		void attack(void) const;
};

#endif
