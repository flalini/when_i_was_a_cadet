/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:34:22 by ijang             #+#    #+#             */
/*   Updated: 2021/04/07 21:52:03 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << std::setfill(' ') << std::setw(8) << "str:";
	std::cout << " " << str << std::endl;
	std::cout << "ptr_str: " << *str_ptr << std::endl;
	std::cout << "ref_str: " << str_ref << std::endl;
	return (0);
}
