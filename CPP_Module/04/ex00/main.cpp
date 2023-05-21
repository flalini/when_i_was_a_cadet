/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:53:59 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 12:41:28 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	jim.getPolymorphed();
	robert.polymorph(joe);
	joe.getPolymorphed();
	robert.polymorph(static_cast<Victim>(joe));

	std::cout << "---" << std::endl;

	Sorcerer copyS(robert);

	Victim copyV(jim);
	Peon copyP(joe);

	std::cout << copyS << copyV << copyP;

	copyV = jim;
	copyS.polymorph(copyV);
	copyV.getPolymorphed();
	copyS = robert;
	copyP = joe;
	copyS.polymorph(copyP);
	copyP.getPolymorphed();

	std::cout << "---" << std::endl;

	return (0);
}
