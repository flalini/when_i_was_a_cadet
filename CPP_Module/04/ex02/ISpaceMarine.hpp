/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:06:15 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 16:15:45 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class ISpaceMarine
{
	public:
		virtual ~ISpaceMarine() {}
		virtual ISpaceMarine *clone(void) const = 0;
		virtual void battleCry(void) const = 0;
		virtual void rangedAttack(void) const = 0;
		virtual void meleeAttack(void) const = 0;
};

#endif
