/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:34:10 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 22:07:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		Character();

		std::string name;
		int equipped;
		AMateria *inventory[4];

	public:
		Character(std::string const &name);
		Character(Character const &other);
		~Character();

		Character &operator=(Character const &other);

		std::string const &getName(void) const;

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
