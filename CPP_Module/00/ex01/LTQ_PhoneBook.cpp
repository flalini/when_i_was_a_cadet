/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LTQ_PhoneBook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:36:10 by ijang             #+#    #+#             */
/*   Updated: 2021/03/21 15:38:12 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LTQ_PhoneBook.hpp"

std::string fields_name[11] = {
	"first name",
	"last name",
	"nickname",
	"login",
	"postal address",
	"email address",
	"phone number",
	"birthday date",
	"favorite meal",
	"underwear color",
	"darkest secret"
};

LTQ_PhoneBook::LTQ_PhoneBook()
{
	this->list_num = 0;
}

int		LTQ_PhoneBook::get_list_num()
{
	return (this->list_num);
}

void	LTQ_PhoneBook::add_new()
{
	int				i;
	std::string		tmp;

	if (this->list_num == 8)
	{
		std::cout << "This phone book is full." << std::endl;
		return ;
	}

	i = -1;
	std::cout << "Add new. index : " << this->list_num + 1 << std::endl;

	while (++i < 11)
	{
		std::cout << fields_name[i] << ":" << std::endl;
		std::getline(std::cin, tmp);
		while (tmp.length() == 0)
			std::getline(std::cin, tmp);
		this->list[this->list_num].set_content(tmp, i);
	}
	++(this->list_num);
	std::cout << "Finish" << std::endl;
}

void	LTQ_PhoneBook::show_list()
{
	int				i;

	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;

	i = -1;
	while (++i < this->list_num)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		if (this->list[i].get_content(0).length() > 10)
			std::cout << this->list[i].get_content(0).substr(0, 9) << ".|";
		else
			std::cout << std::setfill(' ') << std::setw(10) << this->list[i].get_content(0) << "|";
		if (this->list[i].get_content(1).length() > 10)
			std::cout << this->list[i].get_content(1).substr(0, 9) << ".|";
		else
			std::cout << std::setfill(' ') << std::setw(10) << this->list[i].get_content(1) << "|";
		if (this->list[i].get_content(2).length() > 10)
			std::cout << this->list[i].get_content(2).substr(0, 9) << ".|" << std::endl;
		else
			std::cout << std::setfill(' ') << std::setw(10) << this->list[i].get_content(2) << "|" << std::endl;
	}
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
}

void	LTQ_PhoneBook::show_index_all(int index)
{
	int		i;

	i = -1;
	while (++i < 11)
		std::cout << fields_name[i] << " : " << this->list[index].get_content(i) << std::endl;
}
