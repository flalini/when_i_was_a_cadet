/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:06 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 14:57:49 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat ijang("Ijang", 100);
	std::cout << ijang << std::endl;

	Form form1("Taxes", 100, 50);
	std::cout << form1 << std::endl;
	form1.beSigned(ijang);
	std::cout << form1 << std::endl;

	std::cout << "---" << std::endl;

	Form form2("WEBSERVE", 99, 50);
	std::cout << form2 << std::endl;
	try
	{
		ijang.signForm(form2);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form2 << std::endl;

	std::cout << "---" << std::endl;

	try
	{
		Form formException("WEBSERVE", 99, 50);
		std::cout << formException << std::endl;
		formException.beSigned(ijang);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 1000, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 0, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 100, 1000);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 100, 0);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
