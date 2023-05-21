/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:48:04 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 12:57:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Data
{
	std::string 	s1;
	int				n;
	std::string 	s2;
};


void *serialize(void)
{
	std::string alnum = 
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	char *ptr = new char[20];

	for (int i = 0; i < 8; i++)
		ptr[i] = alnum[rand() % alnum.length()];

	*reinterpret_cast<int *>(ptr + 8) = (rand() % 10);

	for (int i = 0; i < 8; i++)
		ptr[i + 12] = alnum[rand() % alnum.length()];

	return (ptr);
}

Data *deserialize(void *ptr)
{
	Data *data = new Data;

	data->s1 = std::string(static_cast<char*>(ptr), 8);
	data->n = *reinterpret_cast<int*>(static_cast<char*>(ptr) + 8);
	data->s2 = std::string(static_cast<char*>(ptr) + 12, 8);
	return (data);
}

int main(void)
{
	srand(time(0));
	char *ptr = reinterpret_cast<char*>(serialize());

	for (int i = 0; i < 8; i++)
		std::cout << *(ptr + i);

	std::cout << *reinterpret_cast<int*>(ptr + 8);

	for (int i = 12; i < 20; i++)
		std::cout << *(ptr + i);

	std::cout << std::endl;
	std::cout << "=================" << std::endl;

	Data *data = deserialize(ptr);

	std::cout << "s1 = " << data->s1 << std::endl;
	std::cout << "n = " << data->n << std::endl;
	std::cout << "s2 = " << data->s2 << std::endl;

	delete ptr;
	delete data;
}