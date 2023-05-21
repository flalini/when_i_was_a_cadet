/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:57:54 by ijang             #+#    #+#             */
/*   Updated: 2021/04/17 10:49:37 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARCTER_HPP
# define ICHARCTER_HPP

class AMateria;
# include "AMateria.hpp"
# include <iostream>
# include <string>

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif