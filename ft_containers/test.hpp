/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:17:37 by ijang             #+#    #+#             */
/*   Updated: 2021/06/26 17:43:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

	void	oneline(std::string const &title);
	void	twoline(std::string const &title);
	void	list_test(void);
	void	vector_test(void);
	void	map_test(void);
	void	stack_test(void);
	void	queue_test(void);

#endif