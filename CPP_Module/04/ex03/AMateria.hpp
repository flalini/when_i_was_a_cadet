/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:55:01 by ijang             #+#    #+#             */
/*   Updated: 2021/04/17 10:50:00 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class ICharacter;
# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	private:
		AMateria();

		std::string _type;
		unsigned int _xp;

	public:
		AMateria(std::string const &type);
		AMateria(std::string const &type, int xp);
		AMateria(AMateria const &other);
		virtual ~AMateria();

		AMateria &operator=(AMateria const &other);

		std::string const &getType() const;
		unsigned int getXP() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif