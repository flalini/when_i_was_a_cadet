/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:00 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 20:43:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

class NotFoundException : public std::exception
{
	const char *what() const throw()
	{
		return ("EasyFindException: not found");
	}
};

template <template<typename, typename> class T>
typename T<int, std::allocator<int> >::iterator easyfind(T<int, std::allocator<int> > &con, int n)
{
	typename T<int, std::allocator<int> >::iterator itpos = std::find(con.begin(), con.end(), n);
	if (itpos != con.end())
		return (itpos);
	else
		throw NotFoundException();
}

#endif
