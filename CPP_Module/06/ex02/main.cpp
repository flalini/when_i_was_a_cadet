/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:23:11 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 13:32:51 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IRT.hpp"

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		Base *p = generate();
		std::cout << "Test " << i << " : ";
		identify_from_pointer(p);
		std::cout << ", ";
		identify_from_reference(*p);
		std::cout << std::endl << std::endl;
		delete p;
	}

	return (0);
}
