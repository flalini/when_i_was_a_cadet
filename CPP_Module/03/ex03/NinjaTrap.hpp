/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:43:15 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 16:20:58 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap();
		NinjaTrap(std::string const &name);
		NinjaTrap(NinjaTrap const &other);
		~NinjaTrap();

		NinjaTrap &operator=(NinjaTrap const &other);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void ninjaShoebox(FragTrap &trap);
		void ninjaShoebox(ScavTrap &trap);
		void ninjaShoebox(ClapTrap &trap);
		void ninjaShoebox(NinjaTrap &trap);
};

#endif
