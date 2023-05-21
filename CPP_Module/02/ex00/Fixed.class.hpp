/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:11:24 by ijang             #+#    #+#             */
/*   Updated: 2021/04/10 17:15:53 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(Fixed const &other);
		~Fixed();

		Fixed &operator=(Fixed const &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
