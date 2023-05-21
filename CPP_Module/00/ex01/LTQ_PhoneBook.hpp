/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LTQ_PhoneBook.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:36:20 by ijang             #+#    #+#             */
/*   Updated: 2021/02/25 15:25:45 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LTQ_PHONEBOOK_HPP
# define LTQ_PHONEBOOK_HPP

# include "PhoneBook_Info.hpp"

class LTQ_PhoneBook
{
	private:
		PhoneBook_Info	list[8];
		int				list_num;

	public:
		LTQ_PhoneBook();

		int		get_list_num();
		void	add_new();
		void	show_list();
		void	show_index_all(int index);
};

#endif