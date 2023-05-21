/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:00:23 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 22:23:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "InternException: Form does not exist";
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form *Intern::CreatePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::CreateRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::CreateShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	Form* (Intern:: *forms[3])(std::string const &target) = {
		&Intern::CreatePresidentialPardonForm,
		&Intern::CreateRobotomyRequestForm,
		&Intern::CreateShrubberyCreationForm
	};

	for (size_t i = 0; i < 3; i++)
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*(forms[i]))(target));
		}
	std::cout << formName << " does not exist" << std::endl;
	throw Intern::FormDoesNotExistException();
	return (NULL);
}
