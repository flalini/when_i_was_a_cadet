/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:46:23 by ijang             #+#    #+#             */
/*   Updated: 2021/04/03 16:08:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony onTheStack("StackPony");

	onTheStack.cry();
}

void ponyOnTheHeap(void)
{
	Pony *onTheHeap;

	onTheHeap = new Pony("HeapPony");
	onTheHeap->cry();
	delete onTheHeap;
}

int main(void)
{
	std::cout << "ponyOnTheStack start" << std::endl;
	ponyOnTheStack();
	std::cout << "ponyOnTheHeap start" << std::endl;
	ponyOnTheHeap();
	return (0);
}
