/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:05:06 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 19:01:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	private:
		ShrubberyCreationForm();

		static std::string const &name;
		static std::string const &tree;

	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		virtual ~ShrubberyCreationForm();

		class TargetFileOpenException: public std::exception {
			virtual const char* what() const throw();
		};
		class WriteException: public std::exception {
			virtual const char* what() const throw();
		};

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		void execute(Bureaucrat const &executor) const;
};

#endif
