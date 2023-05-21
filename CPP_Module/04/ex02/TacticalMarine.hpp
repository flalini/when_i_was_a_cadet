/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:15:21 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 17:24:36 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"
# include "iostream"

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const &other);
		~TacticalMarine();

		TacticalMarine &operator=(TacticalMarine const &other);

		ISpaceMarine *clone(void) const;
		void battleCry(void) const;
		void rangedAttack(void) const;
		void meleeAttack(void) const;
};

#endif
