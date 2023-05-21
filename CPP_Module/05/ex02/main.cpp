/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:19:06 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 20:15:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat ijang("Ijang", 1);
	std::cout << ijang << std::endl;
	Bureaucrat flalini("Flalini", 25);
	std::cout << flalini << std::endl;

	Form *shrub = new ShrubberyCreationForm("home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(ijang);
	shrub->execute(flalini);

	Form *pres = new PresidentialPardonForm("Flalini");
	std::cout << *pres << std::endl;
	ijang.signForm(*pres);
	pres->execute(ijang);

	Form *robot = new RobotomyRequestForm("Ullachon");
	std::cout << *robot << std::endl;
	robot->beSigned(ijang);
	robot->execute(flalini);
	flalini.executeForm(*robot);
	flalini.executeForm(*robot);

	std::cout << "---" << std::endl;

	try
	{
		flalini.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("Ullachon");
		std::cout << robot << std::endl;
		robot.execute(ijang);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Flalini");
		std::cout << pres << std::endl;
		ijang.signForm(pres);
		pres.execute(flalini);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Flalini");
		std::cout << pres << std::endl;
		ijang.signForm(pres);
		flalini.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}