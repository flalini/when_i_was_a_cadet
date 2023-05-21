/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:06 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 11:40:11 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat ijang("Ijang", 100);
	std::cout << ijang << std::endl;
	ijang.increaseGrade();
	std::cout << ijang << std::endl;
	ijang.decreaseGrade();
	std::cout << ijang << std::endl;

	try
	{
		Bureaucrat flalini("Flalini", 0);
		std::cout << flalini << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat flalini("Flalini", 1000);
		std::cout << flalini << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat flalini("Flalini", 1);
		std::cout << flalini << std::endl;
		flalini.increaseGrade();
		std::cout << flalini << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat flalini("Flalini", 150);
		std::cout << flalini << std::endl;
		flalini.decreaseGrade();
		std::cout << flalini << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
