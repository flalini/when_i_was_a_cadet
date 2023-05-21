/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:20:18 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 15:50:45 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *arr, size_t length, void (*f)(T const &elt))
{
	if (arr == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		(*f)(arr[i]);
}

#endif
