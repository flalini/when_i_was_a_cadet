/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Info.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:36:24 by ijang             #+#    #+#             */
/*   Updated: 2021/02/24 17:11:38 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_Info.hpp"

PhoneBook_Info::PhoneBook_Info()
{
	int	i;

	i = -1;
	while (++i < 11)
		this->content[i] = std::string();
}

void			PhoneBook_Info::set_content(std::string str, int i)
{
	this->content[i] = str;
}

std::string		PhoneBook_Info::get_content(int i)
{
	return (this->content[i]);
}
