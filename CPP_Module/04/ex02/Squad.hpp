/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:16:48 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 16:21:50 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad: public ISquad
{
	private:
		int count;
		ISpaceMarine **units;

	public:
		Squad();
		Squad(Squad const &other);
		~Squad();

		Squad &operator=(Squad const &other);

		int getCount(void) const;
		ISpaceMarine *getUnit(int index) const;
		int push(ISpaceMarine *unit);
};

#endif
