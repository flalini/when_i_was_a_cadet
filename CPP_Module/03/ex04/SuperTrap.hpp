/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:21:14 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:21:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
	public:
		SuperTrap();
		SuperTrap(std::string const &name);
		SuperTrap(SuperTrap const &other);
		~SuperTrap();

		SuperTrap &operator=(SuperTrap const &other);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
};

#endif
