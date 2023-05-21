/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:45:49 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:09:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEVENT_HPP
# define ZOMBIEVENT_HPP

# include <random>
# include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string	type;

		static std::string randomName(std::string::size_type length);

	public:
		ZombieEvent();
		virtual ~ZombieEvent();

		void 		setZombieType(std::string const &type);
		Zombie		*newZombie(std::string const &name);
		Zombie		*randomChump(void);
};

#endif
