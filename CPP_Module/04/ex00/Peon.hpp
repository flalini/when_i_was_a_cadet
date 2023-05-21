/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:54:10 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 12:28:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon: public Victim
{
	private:
		Peon();

	public:
		Peon(std::string const &name);
		Peon(Peon const &peon);
		~Peon();

		Peon &operator=(const Peon &other);

		void getPolymorphed(void) const;
};

#endif
