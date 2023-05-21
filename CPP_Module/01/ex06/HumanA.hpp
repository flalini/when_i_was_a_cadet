/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:57:39 by ijang             #+#    #+#             */
/*   Updated: 2021/04/08 00:02:13 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		const Weapon &weapon;

	public:
		HumanA(std::string const &name, const Weapon &weapon);
		~HumanA();

		void attack(void) const;
};

#endif
