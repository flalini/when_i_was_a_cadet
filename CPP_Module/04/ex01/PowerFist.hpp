/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:07:11 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 13:15:05 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const &other);
		~PowerFist();

		void attack(void) const;
};

#endif
