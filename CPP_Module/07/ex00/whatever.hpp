/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:55:19 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 15:20:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T swap = a;
	
	a = b;
	b = swap;
}

template <typename T>
T min(T &a, T &b)
{
	if (a >= b)
		return b;
	return a;
}

template <typename T>
T max(T &a, T &b)
{
	if (a <= b)
		return b;
	return a;	
}

#endif
