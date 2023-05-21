/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:36:40 by ijang             #+#    #+#             */
/*   Updated: 2021/03/21 15:44:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LTQ_PhoneBook.hpp"

int		main()
{
	LTQ_PhoneBook	a;
	std::string		command;
	int				i;

	std::cout << "LTQ_PhoneBook is start." << std::endl;
	std::cout << "There are three commads." << std::endl;
	std::cout << "\"ADD\" \"SEARCH\" \"EXIT\"" << std::endl;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			a.add_new();
		else if (command == "SEARCH")
		{
			if (a.get_list_num() == 0)
			{
				std::cout << "There is no data." << std::endl;
				continue ;
			}
			a.show_list();
			std::cout << "Enter the desired index to show the corresponding data." << std::endl;
			std::cout << "Exit SEARCH by entering an index that is out of range or by entering something else." << std::endl;
			while (1)
			{
				std::cout << "> ";
				std::getline(std::cin, command);
				if (command.length() == 0 || command.find_first_not_of("0123456789") != std::string::npos)
					break ;
				i = std::stoi(command);
				if (i > 0 && i <= a.get_list_num())
					a.show_index_all(i - 1);
				else
					break ;
			}
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Unable to process command." << std::endl;
	}
	std::cout << "Bye." << std::endl;
	return (0);
}