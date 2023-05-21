/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:18:49 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 12:47:24 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade):
	name(name), grade(grade)
{
	if (this->grade < MINGRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > MAXGRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):
	name(other.name), grade(other.grade)
{
	if (this->grade < MINGRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > MAXGRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::increaseGrade(void)
{
	if (this->grade <= MINGRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->grade >= MAXGRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << "Bureaucrat <" << bureaucrat.getName() << ">(Grade : " << bureaucrat.getGrade() << ")";
	return (os);
}
