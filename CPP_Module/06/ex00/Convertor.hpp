/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 02:25:50 by ijang             #+#    #+#             */
/*   Updated: 2021/04/22 12:45:24 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>
# ifndef INT64_MAX
#  define INT64_MAX 9223372036854775807LL
# endif
# ifndef INT64_MIN
#  define INT64_MIN (-INT64_MAX-1)
# endif

class Convertor
{
	private:
		std::string input;
		Convertor();

	public:
		Convertor(std::string input);
		Convertor(const Convertor& ref);
		~Convertor();

		Convertor& operator=(const Convertor& ref);

		void printToChar() const;
		void printToInt() const;
		void printToFloat() const;
		void printToDouble() const;
};

#endif
