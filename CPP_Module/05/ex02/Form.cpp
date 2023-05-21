/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:47:21 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 19:00:46 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int const signGrade, int const executeGrade):
	name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade), target("")
{
	if (signGrade < MINGRADE || executeGrade < MINGRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MAXGRADE || executeGrade > MAXGRADE)
		throw Form::GradeTooLowException();
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade, std::string const &target):
	name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade), target(target)
{
	if (signGrade < MINGRADE || executeGrade < MINGRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MAXGRADE || executeGrade > MAXGRADE)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
	name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade), target(other.target)
{
	if (signGrade < MINGRADE || executeGrade < MINGRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MAXGRADE || executeGrade > MAXGRADE)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char* Form::UnsignedFormException::what() const throw()
{
	return "FormException: Unsigned form can not be executed";
}

Form &Form::operator=(Form const &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

std::string const &Form::getTarget(void) const
{
	return (this->target);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

void Form::execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->executeGrade)
		throw Form::GradeTooLowException();
	if (!this->_signed)
		throw Form::UnsignedFormException();
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "<" << form.getName() << ">(" << ((form.isSigned()) ? "Signed" : "Unsigned")
		<< ") <Sign : " << form.getSignGrade() << ", Execute : "
		<< form.getExecuteGrade() << ">";
	return (os);
}