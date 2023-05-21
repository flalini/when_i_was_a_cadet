/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 02:25:52 by ijang             #+#    #+#             */
/*   Updated: 2021/04/19 02:54:03 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convertor.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: only handle one argument!" << std::endl;
		return (-1);
	}

	Convertor convertor(argv[1]);

	convertor.printToChar();
	convertor.printToInt();
	convertor.printToFloat();
	convertor.printToDouble();
	return (0);
}
