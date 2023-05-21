/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:55:58 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:12:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
	private:
		AWeapon();

		std::string name;
		int apCost;
		int damage;

	public:
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon const &other);
		virtual ~AWeapon();

		AWeapon &operator=(AWeapon const &other);

		std::string const &getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;

		virtual void attack() const = 0;
};

#endif
