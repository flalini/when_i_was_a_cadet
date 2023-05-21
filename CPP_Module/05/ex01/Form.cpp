/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:47:21 by ijang             #+#    #+#             */
/*   Updated: 2021/04/18 14:46:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int const signGrade, int const executeGrade):
	name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < MINGRADE || executeGrade < MINGRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MAXGRADE || executeGrade > MAXGRADE)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
	name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade)
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

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "<" << form.getName() << ">(" << ((form.isSigned()) ? "Signed" : "Unsigned")
		<< ") <Sign : " << form.getSignGrade() << ", Execute : "
		<< form.getExecuteGrade() << ">";
	return (os);
}