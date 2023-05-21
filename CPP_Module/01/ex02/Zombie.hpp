/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:16:35 by ijang             #+#    #+#             */
/*   Updated: 2021/04/06 20:46:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string type;
		std::string name;

		void call_name();

	public:
		Zombie();
		Zombie(std::string const &type, std::string const &name);
		~Zombie();

		void setVar(std::string const &type, std::string const &name);
		void announce(void);
};

#endif
