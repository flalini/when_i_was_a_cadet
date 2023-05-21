/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:06:35 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 21:58:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t amount):
	max(amount)
{
}

Span::Span(Span const &other):
	max(other.max)
{
	this->numbers.clear();
	this->numbers = other.numbers;
}

Span::~Span()
{
	this->numbers.clear();
}

const char* Span::FullSpanException::what() const throw()
{
	return "SpanException: Span is already full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "SpanException: not enough numbers in Span";
}

Span &Span::operator=(Span const &other)
{
	this->max = other.max;
	this->numbers.clear();
	this->numbers = other.numbers;
	return (*this);
}

void Span::addNumber(int value)
{
	if (this->numbers.size() == this->max)
		throw Span::FullSpanException();
	this->numbers.insert(value);
}

size_t Span::shortestSpan(void) const
{
	size_t size = this->numbers.size();
	if (size <= 1)
		throw Span::NotEnoughNumbersException();

	std::multiset<unsigned int>::iterator first = this->numbers.begin();
	std::multiset<unsigned int>::iterator next = ++(this->numbers.begin());
	size_t minDiff = *next++ - *first++;
	while (next != this->numbers.end())
	{
		size_t diff = *next - *first;
		if (diff < minDiff)
			minDiff = diff;
		first++;
		next++;
	}
	return (minDiff);
}

size_t Span::longestSpan(void) const
{
	if (this->numbers.size() <= 1)
		throw Span::NotEnoughNumbersException();

	int biggest = *std::max_element(this->numbers.begin(), this->numbers.end());
	int smallest = *std::min_element(this->numbers.begin(), this->numbers.end());
	return (std::abs(biggest - smallest));
}
