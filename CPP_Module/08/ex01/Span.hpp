/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:06:33 by ijang             #+#    #+#             */
/*   Updated: 2021/04/20 01:35:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <cmath>
# include <algorithm>

class Span
{
	private:
		Span();

		size_t max;
		std::multiset<unsigned int> numbers;

	public:
		Span(size_t amount);
		Span(Span const &other);
		virtual ~Span();

		class FullSpanException: public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughNumbersException: public std::exception {
			virtual const char* what() const throw();
		};

		Span &operator=(Span const &other);

		void addNumber(int value);
		template<typename Iterator>
		void addNumber(Iterator begin, Iterator end);

		size_t shortestSpan(void) const;
		size_t longestSpan(void) const;
};

template<typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
	if (this->numbers.size() + std::distance(begin, end) > this->max)
		throw Span::FullSpanException();
	this->numbers.insert(begin, end);
}

#endif
