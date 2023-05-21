/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRT.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:14:45 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 13:25:36 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRT.hpp"

Base *generate(void)
{
	int r = rand() % 9;

	if (!r)
	{
//		std::cout << "A" << std::endl;
		return (new A);
	}
	if (r < 4)
	{
//		std::cout << "B" << std::endl;
		return (new B);
	}
//	std::cout << "C" << std::endl;
	return (new C);
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C";
}

void identify_from_reference(Base &p)
{
	identify_from_pointer(&p);
}
