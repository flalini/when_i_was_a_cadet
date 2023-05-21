/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:36:34 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 19:08:54 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#define COUNT	5

void forStack(void)
{
	std::cout << "The sun is setting." << std::endl;
	std::cout << "Creating " << COUNT << " Zombie" << std::endl;

	Zombie Zombies[COUNT];
	for (int i = 0; i < COUNT; i++)
		Zombies[i].announce();
	std::cout << "The sun is rising." << std::endl;
}

int main(void)
{
	ZombieEvent walkers;
	ZombieEvent runners;
	Zombie *walkersZombies[COUNT];
	Zombie *runnersZombies[COUNT];

	std::cout << "The sun is setting." << std::endl;
	walkers.setZombieType("Walker");
	std::cout << "Creating " << COUNT << " Walker Zombie" << std::endl;
	for (int i = 0; i < COUNT; i++)
		walkersZombies[i] = walkers.randomChump();
	runners.setZombieType("Runner");
	std::cout << "Creating " << COUNT << " Runner Zombie" << std::endl;
	for (int i = 0; i < COUNT; i++)
		runnersZombies[i] = runners.randomChump();

	std::cout << "The sun is rising." << std::endl;
	std::cout << "Clean All Walker Zombies" << std::endl;
	for (int i = 0; i < COUNT; i++)
		delete walkersZombies[i];
	std::cout << "Clean All Runner Zombies" << std::endl;
	for (int i = 0; i < COUNT; i++)
		delete runnersZombies[i];
	std::cout << std::endl;

	forStack();
	return (0);
}
