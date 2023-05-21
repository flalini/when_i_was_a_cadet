/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:04:20 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 20:46:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vec;
	std::list<int> list;

	vec.push_back(2);
	vec.push_back(-5);
	vec.push_back(99);
	vec.push_back(0);

	list.push_back(8);
	list.push_back(-895);
	list.push_back(785);
	list.push_back(156);

	std::vector<int>::iterator it_find_vec = easyfind(vec, 0);
	std::cout << "Search 0 : " << *it_find_vec << std::endl;
	std::cout << "Previous of 0 in array is : " << *(it_find_vec - 1) << std::endl;

	try
	{
		std::cout << "Search 10000" << std::endl;
		it_find_vec = easyfind(vec, 10000);
		std::cout << *it_find_vec << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::list<int>::iterator it_find_list = easyfind(list, -895);
	std::cout << "Search -895 : " << *it_find_list << std::endl; 
	std::cout << "Previous of -895 in array is : " << *(--it_find_list) << std::endl;
}
