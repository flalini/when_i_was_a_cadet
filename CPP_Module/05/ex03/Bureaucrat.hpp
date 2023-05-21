/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:18:45 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 19:20:39 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;
# include "Form.hpp"

# ifndef MINGRADE
#  define MINGRADE 1
# endif
# ifndef MAXGRADE
#  define MAXGRADE 150
# endif

class Bureaucrat
{
	private:
		Bureaucrat();

		std::string const name;
		int grade;

	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &other);

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		std::string const &getName(void) const;
		int getGrade(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);
		void signForm(Form &form) const;
		void executeForm(Form const &form) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
