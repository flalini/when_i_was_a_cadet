/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:16:46 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 22:08:55 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <random>
# include "Zombie.hpp"

class ZombieHorde
{
	private:
		std::string type;
		int size;
		Zombie *zombies;

		static std::string randomName(std::string::size_type length);

	public:
		ZombieHorde(int size);
		ZombieHorde(std::string const &type, int size);
		~ZombieHorde();	

		void announce(void);
};

#endif
