/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:54:25 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 12:21:49 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
	protected:
		Victim();

		std::string name;

	public:
		Victim(std::string const &name);
		Victim(const Victim &other);
		virtual ~Victim();

		Victim &operator=(const Victim &other);

		std::string const &getName(void) const;
		virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &os, Victim const &victim);

#endif
