/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:47:23 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 19:00:07 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;
# include "Bureaucrat.hpp"

# ifndef bool
#  define bool int
# endif
# ifndef true
#  define true 1
# endif
# ifndef false
#  define false 0
# endif

class Form
{
	private:
		Form();

		std::string const &name;
		bool _signed;
		int const signGrade;
		int const executeGrade;
		std::string const target;

	public:
		Form(std::string const &name, int const signGrade, int const executeGrade);
		Form(std::string const &name, int const signGrade, int const executeGrade, std::string const &target);
		Form(Form const &other);
		virtual ~Form();

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class UnsignedFormException: public std::exception {
			virtual const char* what() const throw();
		};

		Form &operator=(Form const &other);

		std::string const &getName(void) const;
		bool isSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		std::string const &getTarget(void) const;
		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
