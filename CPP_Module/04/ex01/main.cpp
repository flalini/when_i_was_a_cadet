/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:16:56 by ijang             #+#    #+#             */
/*   Updated: 2021/04/16 15:47:38 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main(void)
{
	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	delete me;

	std::cout << "---" << std::endl;

	Character you("you");

	Enemy* s = new SuperMutant();

	you.equip(pr);
	std::cout << you;
	you.equip(pf);
	std::cout << you;
	you.equip(NULL);
	std::cout << you;

	you.attack(s);
	you.equip(pf);
	std::cout << you;
	you.attack(s);
	std::cout << you;
	you.attack(s);
	std::cout << you;
	you.attack(s);
	std::cout << you;
	you.attack(s);
	std::cout << you;

	Enemy* e = new Enemy(51, "Worm");

	you.attack(e);
	std::cout << you;
	you.attack(e);
	std::cout << you;

	Character charaFriend(you);
	std::cout << charaFriend;
	charaFriend = you;
	std::cout << charaFriend;

	SuperMutant m;
	SuperMutant m2(m);
	std::cout << m.getType() << " and " << m2.getType() << std::endl;
	m2 = m;
	std::cout << m.getType() << " and " << m2.getType() << std::endl;

	RadScorpion sc;
	RadScorpion sc2(sc);
	std::cout << sc.getType() << " and " << sc2.getType() << std::endl;
	sc2 = sc;
	std::cout << sc.getType() << " and " << sc2.getType() << std::endl;
	
	you.recoverAP();
	you.recoverAP();
	you.recoverAP();
	you.recoverAP();

	AWeapon *forYou = pr;
	you.equip(forYou);
	std::cout << you;
	*forYou = *pf;
	std::cout << you;

	delete e;
	delete pr;
	delete pf;

	return (0);
}
