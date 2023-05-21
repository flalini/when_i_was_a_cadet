/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:55:59 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:44:08 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"


void    oneline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "-------------------- ";
    std::cout << title;
    std::cout << " -------------------- " << std::endl;
}

void    twoline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "==================== ";
    std::cout << title;
    std::cout << " ==================== " << std::endl;
}

int		main(void)
{
	twoline("List");
	list_test();
    std::cout << "\n\n\n\n\n\n\n" << std::endl;
	twoline("Vector");
	vector_test();
    std::cout << "\n\n\n\n\n\n\n" << std::endl;
	twoline("Map");
	map_test();
    std::cout << "\n\n\n\n\n\n\n" << std::endl;
	twoline("Stack");
	stack_test();
    std::cout << "\n\n\n\n\n\n\n" << std::endl;
	twoline("Queue");
	queue_test();
}
