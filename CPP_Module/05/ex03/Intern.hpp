/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:00:25 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 22:22:53 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();

	class FormDoesNotExistException: public std::exception {
		virtual const char* what() const throw();
	};

	Intern &operator=(Intern const &other);

	Form *CreatePresidentialPardonForm(std::string const &target);
	Form *CreateRobotomyRequestForm(std::string const &target);
	Form *CreateShrubberyCreationForm(std::string const &target);
	Form *makeForm(std::string const &formName, std::string const &target);
};

#endif
