/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:05:03 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 19:04:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const &ShrubberyCreationForm::name = std::string("Shrubbery Creation");

std::string const &ShrubberyCreationForm::tree = std::string(
	"      /\\      \n" \
	"     /\\*\\     \n" \
	"    /\\O\\*\\    \n" \
	"   /*/\\/\\/\\   \n" \
	"  /\\O\\/\\*\\/\\  \n" \
	" /\\*\\/\\*\\/\\/\\ \n" \
	"/\\O\\/\\/*/\\/O/\\\n" \
	"      ||      \n" \
	"      ||      \n" \
	"      ||      "
);

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form(ShrubberyCreationForm::name, 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{
	return "ShrubberyCreationFormException: Cannot open file";
}

const char* ShrubberyCreationForm::WriteException::what() const throw()
{
	return "ShrubberyCreationFormException: Error while writing to the file";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::string const shrubName = (this->getTarget() + "_shrubbery");
	std::ofstream outfile(shrubName, std::ios::out | std::ios::trunc);

	if (!outfile.is_open() || outfile.bad())
		throw TargetFileOpenException();
	outfile << ShrubberyCreationForm::tree;
	if (outfile.bad())
	{
		outfile << std::endl;
		outfile.close();
		throw WriteException();
	}
	outfile << std::endl;
	outfile.close();
}
