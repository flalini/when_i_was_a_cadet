/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:46 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 16:15:25 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad() {};
		virtual int getCount(void) const = 0;
		virtual ISpaceMarine *getUnit(int index) const = 0;
		virtual int push(ISpaceMarine *unit) = 0;
};

#endif
