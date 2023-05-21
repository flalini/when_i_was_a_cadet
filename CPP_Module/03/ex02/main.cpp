/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:09:17 by ijang             #+#    #+#             */
/*   Updated: 2021/04/13 12:22:55 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	srand(time(NULL));

	FragTrap *frag = new FragTrap("FR4G");
	std::cout << std::endl;
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->meleeAttack("CL4P-TP");
	frag->rangedAttack("CL4P-TP");
	frag->takeDamage(24);
	frag->beRepaired(50);
	frag->takeDamage(42);
	frag->takeDamage(100);
	frag->beRepaired(125);
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	std::cout << std::endl;
	delete frag;

	std::cout << "====" << std::endl;

	ScavTrap *scav = new ScavTrap("SC4V");
	std::cout << std::endl;
	scav->challengeNewcomer();
	scav->meleeAttack("CL4P-TP");
	scav->rangedAttack("CL4P-TP");
	scav->takeDamage(24);
	scav->beRepaired(50);
	scav->takeDamage(42);
	scav->takeDamage(100);
	scav->beRepaired(125);
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	scav->challengeNewcomer();
	std::cout << std::endl;
	delete scav;

	return (0);
}
