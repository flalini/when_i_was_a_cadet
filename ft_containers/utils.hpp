/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:34:38 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:11:22 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# ifndef nullptr
#  define nullptr ((void *)0)
# endif
# ifndef bool
#  define bool int
# endif
# ifndef true
#  define true 1
# endif
# ifndef false
#  define false 0
# endif

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	template <typename T>
	struct	Node
	{
		Node	*prev;
		T		data;
		Node	*next;
	};
};

#endif
