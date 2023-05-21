/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:35:35 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 15:16:12 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		Character();

		std::string name;
		int ap;
		AWeapon *weapon;

	public:
		Character(std::string const &name);
		Character(Character const &other);
		~Character();

		Character &operator=(Character const &other);

		std::string const &getName(void) const;
		int getAP(void) const;
		AWeapon *getWeapon(void) const;

		void recoverAP(void);
		void equip(AWeapon *weapon);
		void attack(Enemy *enemy);
};

std::ostream &operator<<(std::ostream &os, Character const &chara);

#endif
